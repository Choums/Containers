/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:37:38 by chaidel           #+#    #+#             */
/*   Updated: 2023/02/10 16:32:27 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


template <class Iterator>
class reverse_iterator {
	
	typedef typename Iterator 										iterator_type;
	typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
	typedef typename iterator_traits<Iterator>::value_type 			value_type;
	typedef typename iterator_traits<Iterator>::difference_type 	difference_type;
	typedef typename iterator_traits<Iterator>::pointer 			pointer;
	typedef typename iterator_traits<Iterator>::reference		 	reference;
	
	protected:
		iterator_type	_cur;

	public:
		/*	default constructor
			Constructs a reverse iterator that points to no object.
			The internal base iterator is value-initialized. */
		reverse_iterator() : _cur() {}
		explicit reverse_iterator(iterator_type it) : _cur(it) {}
		
		template <class Iter> reverse_iterator(const reverse_iterator<Iter>& rev_it) : _cur(rev_it.base()) {}
	
		
		iterator_type	base() {	return (_cur(_cur)); }

		/*	the pre-increment version (1) decrements the base iterator kept by the object
			(as if applying operator-- to it).
		*/
		reverse_iterator&	operator++() {	return (--(*this)); }
		
		/*	The post-increment version (2) returns the value *this had before the call. */
		reverse_iterator	operator++(int)
		{
			reverse_iterator	tmp = *this;
			++(*this);
			return (tmp);
		}

		/*	the pre-decrement version (1) increments the base iterator kept by the object */
		reverse_iterator&	operator--() {	return (++(*this)); }
		
		/*	The post-decrement version (2) returns the value *this had before the call. */
		reverse_iterator	operator--(int)
		{
			reverse_iterator	tmp = *this;
			--(*this);
			return (tmp);
		}

		reverse_iterator	operator-(difference_type n) const
		{	return ((*this) + n); }

		reverse_iterator	operator+(difference_type n) const
		{	return ((*this) - n); }

		/*	Advances the reverse_iterator by n element positions. */
		reverse_iterator	operator+=(diference_type n)
		{
			*this -= n;
			return (*this);
		}

		reverse_iterator	operator-=(diference_type n)
		{
			*this += n;
			return (*this);
		}

		/*	@return Returns a reference to the element pointed to by the iterator.
			@brief Internally, the function decreases a copy of its base iterator
			and returns the result of dereferencing it.
			The iterator shall point to some object in order to be dereferenceable.
		*/
		reverse_iterator	operator*() const
		{
			reverse_iterator	tmp(*this);
			--tmp;
			return (*tmp);
		}

		/*	returns a pointer to the element pointed to by the iterator (in order to access one of its members). */
		reverse_iterator	operator->() const {	return (&(operator*())); }

		/*	Accesses the element located n positions away from the element currently pointed to by the iterator.
			Internally, the function accesses the proper element of its base iterator, returning the same as: base()[-n-1]. */
		reverse_iterator	operator[](difference_type n) const {	return (this->base()[-n - 1]); }

};

