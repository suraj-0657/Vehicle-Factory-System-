/*Abstract Factory Pattern: Design a vehicle factory system which has to produce different
types of cars like orinary and luxury cars and shows prices of that 
according to users choices of cars. */

#include <iostream>
using namespace std;

enum UserCar
{
    MercediesCar,
    FordCar,
    SwiftCar,
    AltoCar
};

enum VehicleFactoryCode
{
    LuxuryVehicleFactory,
    OrdinaryVehicleFactory
};

class Vehicle
{
    public:
    virtual void calculatePrice() = 0;
};

class Mercedies : public Vehicle
{
    public:
    void calculatePrice()
    {
        cout<<"Price of Mercedies car: 4000K"<<endl;
    }
};

class Ford : public Vehicle
{
    public:
    void calculatePrice()
    {
        cout<<"Price of Ford car: 2000K"<<endl;
    }
};

class Swift : public Vehicle
{
    public:
    void calculatePrice()
    {
        cout<<"Price of Swift car: 800K"<<endl;
    }
};

class Alto : public Vehicle
{
    public:
    void calculatePrice()
    {
        cout<<"Price of Alto car: 600K"<<endl;
    }
};

class VehicleFactoryInterface1
{
    public:
    virtual Vehicle* chooseCar(UserCar car) = 0;
};

class LuxuryVehicle : public VehicleFactoryInterface1
{
    public:
    Vehicle* chooseCar(UserCar car)
    {
        switch(car)
        {
            case MercediesCar: return (new Mercedies);
            case FordCar:      return (new Ford);
            default:        return NULL;
        }
    }
};

class OrdinaryVehicle : public VehicleFactoryInterface1
{
    public:
    Vehicle* chooseCar(UserCar car)
    {
        switch(car)
        {
            case SwiftCar: return (new Swift);
            case AltoCar:      return (new Alto);
            default:        return NULL;
        }
    }
};

class VehicleFactoryInterface2
{
    public:
    virtual VehicleFactoryInterface1* chooseVehicleFactory(VehicleFactoryCode code) = 0;
};

class VehicleFactory2 : public VehicleFactoryInterface2
{
    public:
    VehicleFactoryInterface1* chooseVehicleFactory(VehicleFactoryCode code)
    {
        switch(code) 
        {
            case LuxuryVehicleFactory: return (new LuxuryVehicle);
            case OrdinaryVehicleFactory: return (new OrdinaryVehicle);
            default: return NULL;
        }
    }
};

int main() {
	VehicleFactoryInterface2 *vehicleFac2 = new VehicleFactory2;
	VehicleFactoryInterface1 *vehicleFac1 = vehicleFac2->chooseVehicleFactory(LuxuryVehicleFactory);
	Vehicle *vehicle = vehicleFac1->chooseCar(MercediesCar);
	vehicle->calculatePrice();
	
	vehicleFac1 = vehicleFac2->chooseVehicleFactory(OrdinaryVehicleFactory);
	vehicle = vehicleFac1->chooseCar(SwiftCar);
	vehicle->calculatePrice();
	return 0;
}
