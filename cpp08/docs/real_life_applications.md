# C++ Module 08 — Real-Life Applications

> Where you'll use these concepts when working at a company.

---

## 1. Generic Programming with Templates

### In the codebase
`easyfind` works with any container type via templates.

### At work

**API response parsing** — You write a single `findField<T>()` function that can search through any JSON-like container (arrays, maps, nested objects) regardless of the underlying data structure.

```cpp
// Your team's internal data layer
template <typename Container>
typename Container::const_iterator
findByPredicate(const Container& data, std::function<bool(const typename Container::value_type&)> pred) {
    return std::find_if(data.begin(), data.end(), pred);
}

// Used by the HTTP handler team, the analytics team, the ML pipeline team...
auto user = findByPredicate(users, [](const User& u) { return u.email == target; });
auto log  = findByPredicate(logs, [](const LogEntry& l) { return l.severity > 3; });
```

**When you'll see this**: Shared utility libraries, serialization frameworks, database abstraction layers, anywhere code needs to be container-agnostic.

---

## 2. STL Containers — Choosing the Right One

### In the codebase
You used `vector`, `list`, and `stack`.

### At work

The container choice directly impacts performance at scale:

| Scenario | Best Container | Why |
|---|---|---|
| HTTP request pool | `std::deque` | Fast push/pop from both ends |
| User session cache | `std::unordered_map` | O(1) lookup by session ID |
| Event log | `std::vector` | Append-only, cache-friendly iteration |
| Task scheduler | `std::priority_queue` | Always process highest-priority task first |
| Undo/Redo system | `std::stack` | LIFO — last action is first to undo |
| Sorted leaderboard | `std::set` / `std::map` | Auto-sorted, O(log n) insert |
| Chat message history | `std::list` | Frequent mid-sequence insertions (reactions, edits) |

**Real example**: At a fintech company, switching from `std::map` to `std::unordered_map` for a transaction lookup table reduced p99 latency from 12ms to 2ms on a 10M-record dataset.

---

## 3. STL Algorithms — Don't Reinvent the Wheel

### In the codebase
You used `std::find`, `std::sort`.

### At work

**Data pipeline processing** — You're building an ETL (Extract-Transform-Load) system:

```cpp
// Filter invalid records
auto valid_end = std::remove_if(records.begin(), records.end(),
    [](const Record& r) { return r.timestamp == 0; });
records.erase(valid_end, records.end());

// Deduplicate
std::sort(records.begin(), records.end());
auto unique_end = std::unique(records.begin(), records.end());
records.erase(unique_end, records.end());

// Compute statistics
auto [min_it, max_it] = std::minmax_element(records.begin(), records.end(),
    [](const Record& a, const Record& b) { return a.value < b.value; });
```

**Why this matters**:
- **Code review speed** — Reviewers instantly understand `std::remove_if` vs. a 15-line loop
- **Bug surface** — STL algorithms are tested by millions; your loop is tested by you
- **Performance** — `std::sort` uses introsort (hybrid quick/heap/insertion), outperforming naive quicksort

---

## 4. Iterator Ranges — The Universal Interface

### In the codebase
`addRange(begin, end)` in Span, iterators in MutantStack.

### At work

**Batch database inserts** — Instead of inserting records one-by-one:

```cpp
// Bad: 10,000 individual INSERT statements
for (auto& record : records)
    db.insert(record);  // 10,000 network round-trips!

// Good: batch insert using iterator range
db.insertBatch(records.begin(), records.end());  // 1 round-trip
```

**Streaming data processing** — Process data without loading everything into memory:

```cpp
// Process a 50GB log file line by line
std::ifstream file("access.log");
std::istream_iterator<std::string> begin(file), end;
auto error_count = std::count_if(begin, end,
    [](const std::string& line) { return line.find("ERROR") != std::string::npos; });
```

---

## 5. Adapter Pattern — Extending Restricted Interfaces

### In the codebase
`MutantStack` adds iterators to `std::stack`.

### At work

**Wrapping third-party SDKs** — You're integrating a payment gateway that has a rigid API:

```cpp
// Third-party SDK (you can't modify)
class PaymentSDK {
public:
    void charge(double amount);
    void refund(std::string txn_id);
};

// Your adapter adds logging, metrics, retry logic
class InstrumentedPayment : public PaymentSDK {
public:
    void charge(double amount) {
        metrics::record("payment.attempt", amount);
        try {
            PaymentSDK::charge(amount);
            metrics::record("payment.success", amount);
        } catch (...) {
            metrics::record("payment.failure", amount);
            throw;
        }
    }
};
```

**Other uses**: Adding thread-safety to a non-thread-safe container, adding observability to a queue, making a legacy API conform to a modern interface.

---

## 6. Exception Handling — Production Error Management

### In the codebase
`Span` throws `std::length_error` and `std::out_of_range`.

### At work

**Microservice error boundaries** — Every service endpoint needs structured error handling:

```cpp
Response handleRequest(const Request& req) {
    try {
        auto user = userService.find(req.userId);    // throws if not found
        auto order = orderService.create(user, req);  // throws if invalid
        return Response::ok(order.toJson());
    }
    catch (const NotFoundException& e) {
        return Response::notFound(e.what());          // 404
    }
    catch (const ValidationError& e) {
        return Response::badRequest(e.what());        // 400
    }
    catch (const std::exception& e) {
        logger::error("Unhandled: {}", e.what());
        return Response::serverError("Internal error"); // 500
    }
}
```

**Best practices in production**:
- Never catch `std::exception` and silently swallow it
- Log stack traces for unexpected exceptions
- Use custom exception hierarchies for domain-specific errors
- In performance-critical paths (game loops, HFT), prefer error codes over exceptions

---

## 7. RAII & Resource Management (Orthodox Canonical Form)

### In the codebase
`Span`'s copy constructor, assignment operator, and destructor manage the internal vector.

### At work

**Database connection pools, file handles, network sockets** — any resource that must be released:

```cpp
class DatabaseConnection {
    MYSQL* conn_;
public:
    DatabaseConnection(const std::string& host) {
        conn_ = mysql_real_connect(/* ... */);
        if (!conn_) throw std::runtime_error("DB connection failed");
    }
    ~DatabaseConnection() { mysql_close(conn_); }  // ALWAYS released

    // Prevent accidental copies (would double-close the connection)
    DatabaseConnection(const DatabaseConnection&) = delete;
    DatabaseConnection& operator=(const DatabaseConnection&) = delete;
};

void processQuery() {
    DatabaseConnection db("prod-db.internal");  // acquired
    db.query("SELECT ...");
    // if an exception is thrown HERE, the destructor still fires
}  // released automatically — no leaks, guaranteed
```

**This is THE most important C++ pattern**. It's why C++ doesn't need a garbage collector. Master it, and you'll never have resource leaks.

---

## Summary: Module 08 Skill Map

| Concept | Junior Use | Senior Use |
|---|---|---|
| Templates | Write generic utility functions | Design type-safe plugin architectures |
| Containers | Pick vector/list/map | Profile and select based on access patterns & cache behavior |
| Algorithms | Replace loops with `std::find` | Compose algorithm chains for data pipelines |
| Iterators | Traverse containers | Build custom iterators for streaming data, lazy evaluation |
| Adapters | Inherit and extend | Design facade/adapter layers for third-party integrations |
| Exceptions | Throw on error | Build exception hierarchies, error boundaries, retry policies |
| RAII/OCF | Copy objects safely | Manage connections, locks, GPU memory, file handles |
