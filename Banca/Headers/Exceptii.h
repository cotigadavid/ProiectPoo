#include <stdexcept>
#include <string>

class eroare_app : public std::runtime_error {
public:
    explicit eroare_app(const std::string& msg) : std::runtime_error(msg) {}
};

class eroare_fisier : public eroare_app {
public:
    explicit eroare_fisier(const std::string& msg) : eroare_app(msg) {}
};