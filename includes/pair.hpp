/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:37:51 by chaidel           #+#    #+#             */
/*   Updated: 2023/02/09 10:37:52 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft 
{
	template<typename _T1, typename _T2>
    struct pair
    {
		typedef _T1 first_type;    // @c first_type is the first bound type
		typedef _T2 second_type;   // @c second_type is the second bound type

		// default (1)	pair(); Constructs a pair object with its elements value-initialized.
		pair() : first(first_type), second(second_type) {}

		// copy (2)	template<class U, class V> pair (const pair<U,V>& pr);
		//  copy / move constructor (and implicit conversion)
		// The object is initialized with the contents of the pr pair object.
		// The corresponding member of pr is passed to the constructor of each of its members.
		template<class U, class V>
		pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {}

		// initialization (3)	pair (const first_type& a, const second_type& b);
		// Member first is constructed with a and member second with b.
		pair (const first_type& a, const second_type& b) : first(a), second(b) {}


		pair& operator= (const pair& pr)
		{
			if (this != &pr)
			{
				first = pr.first;
				second = pr.second;
			}
			return (*this);
		}

		_T1 first;                 // @c first is a copy of the first object
		_T2 second;                // @c second is a copy of the second object
	};

	template <class T1, class T2>
	pair<T1, T2> make_pair (T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}


	// void	swap(pair& pr)
	// {
	// 	std::swap(first, pr.first);
	// 	std::swap(second, pr.second);
	// }

	template<class T>
	void	swap(T&	a, T&b)
	{
		T	c(a);
		a = b;
		b = c;
	}


	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{	return (lhs.fisrt == rhs.first && lhs.second == rhs.second); }

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{	return !(lhs == rhs); }

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{	return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second)); }

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{	return (!(rhs < lhs)) }

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{	return (rhs < lhs); }

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{	return (!(lhs < rhs)); }



}