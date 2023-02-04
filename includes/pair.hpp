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

		_T1 first;                 // @c first is a copy of the first object
		_T2 second;                // @c second is a copy of the second object
	};
}