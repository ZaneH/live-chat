#pragma once

#include <string>
#include <optional>

class User {
    public:
        User(std::string username, std::optional<std::string> displayName = std::nullopt);

        const std::string& getUsername() const;
        std::string getDisplayName() const;

    private:
        std::string username;
        std::optional<std::string> displayName;
};
