/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyComp_main.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2022/09/13 15:31:26 by xchalle          ###   ########.fr       */
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
	ft::set<int> myset;
  int highest;

  ft::set<int>::key_compare mycomp = myset.key_comp();

  for (int i=0; i<=9; i++) myset.insert(i);

  std::cout << "myset contains:";
  highest=*(myset.rbegin());
  ft::set<int>::iterator it=myset.begin();
  do {
	  std::cout << ' ' << *it;
  } while ( mycomp(*(++it),highest) );

  std::cout << '\n';

  return 0;
}