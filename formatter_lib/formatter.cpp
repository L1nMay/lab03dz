#include "formatter.h"
#include <algorithm>

namespace formatter {

std::string format(const std::string& input) {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

}
