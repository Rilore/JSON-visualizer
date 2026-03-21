#include <gtest/gtest.h>

#include <nlohmann/json.hpp>

TEST(MainTest, HelloWorld) {
  nlohmann::json message_json;
  message_json["message"] = "Hello, World!";
  ASSERT_EQ(message_json["message"], "Hello, World!");
}
