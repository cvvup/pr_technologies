#include <iostream>
#include <string>

class Logger {
public:
  virtual void log(std::string message) = 0;
  virtual ~Logger() = default;
};

class FileLogger : public Logger {
public:
  void log(std::string message) override {
    std::cout << "Logging to file: " << message << std::endl;
  }
};

class ConsoleLogger : public Logger {
public:
  void log(std::string message) override {
    std::cout << "Logging to console: " << message << std::endl;
  }
};

class LoggerFactory {
public:
  virtual Logger *createLogger() = 0;

  void logMessage(const std::string &message) {
    Logger *logger = createLogger();
    logger->log(message);
  }

  virtual ~LoggerFactory() = default;
};

class FileLoggerFactory : public LoggerFactory {
public:
  Logger *createLogger() override { return new FileLogger(); }
};

class ConsoleLoggerFactory : public LoggerFactory {
public:
  Logger *createLogger() override { return new ConsoleLogger(); }
};

int main() {
  FileLoggerFactory fileLoggerFactory;
  fileLoggerFactory.logMessage("This is a file log message.");

  ConsoleLoggerFactory consoleLoggerFactory;
  consoleLoggerFactory.logMessage("This is a console log message.");
}
