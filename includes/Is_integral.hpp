/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:36:39 by chaidel           #+#    #+#             */
/*   Updated: 2023/01/31 14:41:01 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*
 *	c'est de faire en 3 etapes
 *	tu code true type et false type
 *	qui renvoie respectivement true et false
 *	ensuite tu fais une struc qui appelle false_type
 *	et tu fais l'ensemble des templates de specialisation pour is_integral est true
 *	donc qui appellera is_true
 *	et ensuite tu code le
 *	la struc is_integral qui appelle la precedente fonctions qui envoie le typename T
 *	mais typename doit passer par remove_cv pour enlever les typages genre : const, volatile et const volatile
*/


typedef integral_constant<bool,true> true_type;
typedef integral_constant<bool,false> false_type;

template <class T, T v>
struct integral_constant {
  static constexpr T value = v;
  typedef T value_type;
  typedef integral_constant<T,v> type;
  constexpr operator T() { return v; }
};

/*
 *	Trait class that identifies whether T is an integral type.
 *	It inherits from integral_constant as being either true_type or false_type, depending on whether T is an integral type:
*/

template <class T>
struct	is_intergral : integral_constant {
	bool	value_type;
	T		type;
};