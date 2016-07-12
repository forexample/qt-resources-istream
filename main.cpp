#include <iostream> // std::cerr
#include <sstream> // std::stringstream

#include <QFile>
#include <QTextStream>

#include <foo.hpp>

int main(int argc, char *argv[]) {
  QFile inputFile(":/config.ini");
  if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    std::cerr << "Can't open file" << std::endl;
    return EXIT_FAILURE;
  }

  QTextStream in(&inputFile);
  const QString all = in.readAll();
  inputFile.close();

  std::stringstream stream;
  stream << all.toStdString();

  foo(stream);
}
