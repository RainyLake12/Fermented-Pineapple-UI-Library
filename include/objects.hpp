#include <map>
#include <vector>
#include <functional>
#include <frame.hpp>
#include <string>
#include <any>

class FPULObj
{
    std::map<int, std::function<int (...)>*> eventHandlers;
    std::map<std::string, std::any> properties;
    std::vector<FPULObj> childen;
    int render(frame f);
};