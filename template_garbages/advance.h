#pragma once
#include <type_traits>
#include <iterator>

template<typename It>
constexpr auto IsRandomAccessIterator = std::is_convertible_v<typename std::iterator_traits<It>::iterator_category, std::random_access_iterator_tag>;

template <typename It, typename Dist,
	typename = std::enable_if_t<!std::is_convertible_v<typename std::iterator_traits<It>::iterator_category, std::random_access_iterator_tag> > >
	void Advance(It& it, Dist dist) {
	for (Dist ctr = 0; ctr < dist; ctr++) {
		++it;
	}
}

template <typename It, typename Dist>
std::enable_if_t<IsRandomAccessIterator<It> >
Advance(It& it, Dist dist) {
	it += dist;
}


template <typename It, typename Dist >
void Advance_cpp17(It& it, Dist dist) {
	if constexpr (std::is_convertible_v<typename std::iterator_traits<It>::iterator_category, std::random_access_iterator_tag>) {
		it += dist;
	}
	else {
		for (Dist ctr = 0; ctr < dist; ctr++) {
			++it;
		}
	}
}

