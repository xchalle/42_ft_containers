/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyComp_main.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2022/09/13 15:22:22 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"
#include <set>



template <class T>
void	print(ft::set<T>& lst)
{
	for (typename ft::set<T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}

int main ()
{
	std::set<int> myset;
  int highest;

  std::set<int>::key_compare mycomp = myset.key_comp();

  for (int i=0; i<=5; i++) myset.insert(i);

  std::cout << "myset contains:";
	std::set<int>::iterator ite=myset.end();
	--ite;
	std::cout << *ite << std::endl;
  highest=*(myset.rbegin());
  std::set<int>::iterator it=myset.begin();
  do {
	  std::cout << ' ' << *it;
  } while ( mycomp(*(++it),highest) );

  std::cout << '\n';

  return 0;
}
