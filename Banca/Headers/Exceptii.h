#pragma once

#include <stdexcept>

class eroare_app : public std::exception { using exception::exception; };
class eroare_fisier : public eroare_app { using eroare_app::eroare_app; };