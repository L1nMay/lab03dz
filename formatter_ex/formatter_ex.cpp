#include "formatter_ex.h"
#include <algorithm>

namespace formatter_ex {

std::string formatString(const std::string& str) {
    std::string formatted = str;
    std::transform(formatted.begin(), formatted.end(), formatted.begin(), ::toupper);
    return formatted;
}

}
