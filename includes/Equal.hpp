/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:59:35 by chaidel           #+#    #+#             */
/*   Updated: 2023/02/05 19:09:09 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <class InputIterator1, class InputIterator2>
  bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
{
  while (first1 != last1)
  {
	if (!(*first1 == *first2))
		return (false);
	++first1;
	++first2;
  }
  return (true);
}

