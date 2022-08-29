#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP
namespace ft
{
	template< class T, T val>
	struct integral_constant
	{
		typedef T value_type;
		typedef integral_constant<T, val> type;
		static const T value = val;
	};

	template <class T, T val>
		T const integral_constant<T, val>::value;

	template <bool val>
		struct integral_constant<bool, val>
		{
			typedef bool value_type;
			typedef integral_constant<bool, val> type;
			static const bool value = val;
		};
	template <bool val>
		bool const integral_constant<bool, val>::value;

	typedef ft::integral_constant<bool, true> true_type;
	typedef ft::integral_constant<bool, false> false_type;

	//template <class T>
	//struct is_integral : public integral_constant<bool, T>
	//{};

	template <class T>
		struct is_integral : public false_type{};
	template <class T>
		struct is_integral<const T> : public is_integral<T> {};
	template <class T>
		struct is_integral<volatile const T> : public is_integral<T>{};
	template <class T>
		struct is_integral<volatile T> : public is_integral<T>{};

	template <>
		struct is_integral<bool> : public ft::true_type{};
	template <>
		struct is_integral<char> : public ft::true_type{};
	template <>
		struct is_integral<wchar_t> : public ft::true_type{};
	template <>
		struct is_integral<short> : public ft::true_type{};
	template <>
		struct is_integral<int> : public ft::true_type{};
	template <>
		struct is_integral<long> : public ft::true_type{};
	template <>
		struct is_integral<long long> : public ft::true_type
	{};
}
#endif
