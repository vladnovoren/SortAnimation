#include "app.hpp"


int main() {
  App& app = App::GetInstance();
  app.Exec();
  return 0;
}