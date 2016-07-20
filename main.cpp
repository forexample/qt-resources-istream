#include <iostream> // std::cerr
#include <sstream> // std::stringstream

#include <QFile>
#include <QTextStream>

#include <foo.hpp>

class QtStream: public std::basic_streambuf<char> {
 public:
  using Base = std::basic_streambuf<char>;

  QtStream(QByteArray& byte_array) {
    Base::setg(
        byte_array.data(),
        byte_array.data(),
        byte_array.data() + byte_array.size()
    );
  }
};

int main(int argc, char *argv[]) {
  QFile inputFile(":/gemma.png");
  if (!inputFile.open(QIODevice::ReadOnly)) {
    std::cerr << "Can't open file" << std::endl;
    return EXIT_FAILURE;
  }

  QByteArray raw(inputFile.readAll());
  QtStream streambuf(raw);
  std::istream stream(&streambuf);

  foo(stream);
}
