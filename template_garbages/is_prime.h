#pragma once

constexpr bool IsPrime(unsigned d) {
	if (d < 2) return false;
	for (auto divider{ d / 2 }; divider > 1; --divider) {
		if (d % divider == 0) {
			return false;
		}
	}
	return true;
}