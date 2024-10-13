#pragma once

#include <memory>
#include <vector>
#include <Print.h>

extern "C" {
    struct lua_State;
}

class Lua {
public:
    explicit Lua();

    void run(const char* script, Print* output = nullptr);

    void load(const char* fileName, Print* output = nullptr);

    void call(const char* func, const std::vector<std::string>& argv, Print* output = nullptr);

    void addModule(const char* name, int(*loadFunc)(lua_State*));

private:
    lua_State* m_state;
    std::mutex m_stateMutex;
};
