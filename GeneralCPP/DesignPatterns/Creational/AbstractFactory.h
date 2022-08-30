#include <utility>

class Car{

    std::string m_tire;
    std::string m_body;

public:
    Car(std::string tire, std::string body):
    m_tire(std::move(tire)),
    m_body(std::move(body)){

    }

    [[nodiscard]] std::string getTireType() const noexcept {return m_tire;}
    [[nodiscard]] std::string getBodyType() const noexcept {return m_body;}
};


class CarFactory {

public:
    virtual ~CarFactory() = default;
    virtual Car* buildCar() = 0;
};

class BasicCarFactory : public CarFactory{

public:
    Car* buildCar() override {
        return new Car("Basic", "Aluminium");
    }
};

class LuxuryCarFactory : public CarFactory {

public:
    Car* buildCar() override {
        return new Car("Luxury", "Gold");
    }
};