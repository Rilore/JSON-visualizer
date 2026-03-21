#include <QApplication>
#include <QDebug>
#include <QString>
#include <nlohmann/json.hpp>

#include "mainwindow.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  MainWindow window;
  window.show();

  nlohmann::json msg_json;
  msg_json["message"] = QString("Hello, World!").toStdString();

  qDebug() << QString::fromStdString(msg_json["message"].get<std::string>());

  return app.exec();
}
