#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehiculo
{
    friend class RegistroPropiedad;

public:
    Vehiculo(string marca, string modelo, string vin)
        : marca_(marca), modelo_(modelo), vin_(vin) {}

    // Getters
    string getMarca() const { return marca_; }
    string getModelo() const { return modelo_; }
    string getVin() const { return vin_; }

    void mostrarDatos() const
    {
        cout << "Marca: " << marca_ << endl;
        cout << "Modelo: " << modelo_ << endl;
        cout << "VIN: " << vin_ << endl;
        cout << "--------------------" << endl;
    }

private:
    string marca_;
    string modelo_;
    string vin_;
};

class RegistroPropiedad
{
public:
    RegistroPropiedad(Vehiculo *v) : vehiculo_(v){};

    void agregarPropietario(string propietario)
    {
        propietarios_.push_back(propietario);
    }

    vector<string> getPropietarios() const { return propietarios_; }

    void mostrarPropietarios() const
    {
        cout << "-------------------" << endl;
        cout << "Historial de propietarios para el vehiculo con VIN: " << vehiculo_->getVin() << endl;
        for (const auto &propietario : propietarios_)
        {
            cout << propietario << endl;
        }
        cout << "-------------------" << endl;
    }

private:
    vector<string> propietarios_;
    Vehiculo *vehiculo_;
};

void actualizarRegistro(Vehiculo &v, RegistroPropiedad &registro, const string &nuevoPropietario)
{
    std::cout << "Actualizar registro para vehiculo con VIN: " << v.getVin() << std::endl;
    registro.agregarPropietario(nuevoPropietario);
};

int main(int argc, const char **argv)
{

    Vehiculo miVehiculo("Toyota", "Corolla", "12VINXY2");
    RegistroPropiedad registro(&miVehiculo);

    registro.agregarPropietario("Juan Perez");
    registro.agregarPropietario("Maria Lopez");

    miVehiculo.mostrarDatos();
    registro.mostrarPropietarios();

    actualizarRegistro(miVehiculo, registro, "Carlos Ramirez");

    registro.mostrarPropietarios();

    return 0;
}