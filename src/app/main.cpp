#include <QApplication>
#include <nlohmann/json.hpp>

#include "mainwindow.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  MainWindow window;
  window.show();

  nlohmann::json msg_json;

  return QApplication::exec();
}
