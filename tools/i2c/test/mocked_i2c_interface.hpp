#pragma once

#include "../i2c_interface.hpp"

#include <gmock/gmock.h>

namespace i2c
{

class MockedI2CInterface : public I2CInterface
{
  public:
    virtual ~MockedI2CInterface() = default;

    MOCK_METHOD(void, open, (), (override));
    MOCK_METHOD(bool, isOpen, (), (const, override));
    MOCK_METHOD(void, close, (), (override));

    MOCK_METHOD(void, read, (uint8_t & data), (override));
    MOCK_METHOD(void, read, (uint8_t addr, uint8_t& data), (override));
    MOCK_METHOD(void, read, (uint8_t addr, uint16_t& data), (override));
    MOCK_METHOD(void, read,
                (uint8_t addr, uint8_t& size, uint8_t* data, Mode mode),
                (override));

    MOCK_METHOD(void, write, (uint8_t data), (override));
    MOCK_METHOD(void, write, (uint8_t addr, uint8_t data), (override));
    MOCK_METHOD(void, write, (uint8_t addr, uint16_t data), (override));
    MOCK_METHOD(void, write,
                (uint8_t addr, uint8_t size, const uint8_t* data, Mode mode),
                (override));
};

std::unique_ptr<I2CInterface>
    create(uint8_t /*busId*/, uint8_t /*devAddr*/,
           I2CInterface::InitialState /*initialState*/)
{
    return std::make_unique<MockedI2CInterface>();
}

} // namespace i2c
