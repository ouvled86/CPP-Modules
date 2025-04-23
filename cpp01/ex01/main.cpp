/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:49:45 by ouel-bou          #+#    #+#             */
/*   Updated: 2025/04/03 14:11:08 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {

  int N = 10;
  Zombie *zombies = zombieHorde(N, "meowski");
  for (int i = 0; i < N; i++) {
    if (zombies) {
      std::cout << "Zombie no " << i + 1 << " ";
      zombies[i].announce();
    }
  }
  delete[] zombies;
}
