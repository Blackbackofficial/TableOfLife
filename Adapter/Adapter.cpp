#include "Adapter.h"

const std::vector<int>& Adapter::GetResult(int) const {}

Adapter::Adapter() {}

Adapter::Adapter(std::shared_ptr <IDatabase> &t_db) {}

Adapter::~Adapter() {}

