#pragma once

#include <iostream>
#include <string>

template<typename T>
class SecureContainer {
public:
    void Set(const T& value) {
        encryptedValue = Encrypt(value);
    }

    T Get() {
        return Decrypt(encryptedValue);
    }

private:
    T encryptedValue;
    static const char key = 'K';

    std::string Encrypt(const T& value) {
        std::string str = value;
        for (char& c : str) {
            c ^= key;
        }
        return str;
    }

    T Decrypt(const std::string& encrypted) {
        std::string decrypted = encrypted;
        for (char& c : decrypted) {
            c ^= key;
        }
        return decrypted;

    }
    template <typename T>
    friend void PrintEncryptedValue(const SecureContainer<T>& sc);
};

template <typename T>
void PrintEncryptedValue(const SecureContainer<T>& sc) {
    std::cout << sc.get() << std::endl;
}
