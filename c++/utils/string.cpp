#include <vector>
#include <string>
#include <cctype>
#include <locale>

namespace utils {
    namespace string {
        // trim from start (in place)
        static inline void ltrim(std::string &s) {
            s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
                return !std::isspace(ch);
            }));
        }

        // trim from end (in place)
        static inline void rtrim(std::string &s) {
            s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
                return !std::isspace(ch);
            }).base(), s.end());
        }

        // trim from both ends (in place)
        static inline void trim(std::string &s) {
            ltrim(s);
            rtrim(s);
        }

        // trim from start (copying)
        static inline std::string ltrim_copy(std::string s) {
            ltrim(s);
            return s;
        }

        // trim from end (copying)
        static inline std::string rtrim_copy(std::string s) {
            rtrim(s);
            return s;
        }

        // trim from both ends (copying)
        static inline std::string trim_copy(std::string s) {
            trim(s);
            return s;
        }

        std::vector<std::string> split_string(std::string to_split, std::string delimiter) {
            size_t pos = 0;
            std::string token;
            std::vector<std::string> to_return = std::vector<std::string>();
            while ((pos = to_split.find(delimiter)) != std::string::npos) {
                token = to_split.substr(0, pos);
                to_return.push_back(token);
                to_split.erase(0, pos + delimiter.length());
            }
            return to_return;
        }
    }
}