#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <regex>


using namespace std;

class Persona{
    protected:
    string Nombre, Apellidos, Domicilio, Localidad, Postal, Telefono, DNI;
    string fechaNacimiento;
    
    public:
    Persona(string nombre, string apellidos, string domicilio, string localidad, string postal, string telefono, string dni, string fecha) 
        : Nombre(nombre), Apellidos(apellidos), Domicilio(domicilio), Localidad(localidad), Postal(postal), Telefono(telefono), DNI(dni), fechaNacimiento(fecha){}

    string getFechaNacimiento() const {
        return fechaNacimiento;
    }

    string getNombre() const {
        return Nombre;
    }
    string getApellidos() const {
        return Apellidos;
    }
    string getDomicilio() const {
        return Domicilio;
    }
    string getLocalidad() const {
        return Localidad;
    }
    string getPostal() const {
        return Postal;
    }
    string getTelefono() const {
        return Telefono;
    }
    string getDNI() const {
        return DNI;
    }
   
    void setNombre(string nombre){
        Nombre = nombre;
    }
    void setApellidos(string apellidos){
        Apellidos = apellidos;
    }
    void setDomicilio(string domicilio){
        Domicilio = domicilio;
    }
    void setLocalidad(string localidad){
        Localidad = localidad;
    }
    void setPostal(string postal){
        Postal = postal;
    }
    void setTelefono(string telefono){
        Telefono = telefono;
    }
     void setDNI(string dni){
        DNI = dni;
    }
   void setFechaNacimiento(string fecha) {
        fechaNacimiento = fecha;
}
};


class Paciente : public Persona {
public:
   Paciente(string nombre, string apellidos, string dni, string fecha, string domicilio, string localidad, string postal, string telefono)
    : Persona(nombre, apellidos, domicilio, localidad, postal, telefono, dni, fecha) {}
};



class Empleado : public Persona{
    private:
        string Departamento;
        string Categoria;

    public:
    Empleado(string nombre, string apellidos, string dni, string fecha, string domicilio, string localidad, string postal, string telefono, string departamento, string categoria)
    : Persona(nombre, apellidos, domicilio, localidad, postal, telefono, dni, fecha), Departamento(departamento), Categoria(categoria) {}

    string getDepartamento() const { return Departamento; }
    string getCategoria() const { return Categoria; }

    void setDepartamento(string departamento){
        Departamento = departamento;
    }    
    void setCategoria(string categoria){
        Categoria = categoria;
    }
};

bool isStringVaziaOuEspacos(const string& str) {
    return str.empty() || str.find_first_not_of(' ') == string::npos;
}

bool validarFecha(const std::string& fecha) {
    std::regex formatoFecha(R"(^\d{2}/\d{2}/\d{4}$)");
    if (!std::regex_match(fecha, formatoFecha)) {
        return false;
    }

    int dia, mes, anyo;
    std::sscanf(fecha.c_str(), "%d/%d/%d", &dia, &mes, &anyo);

    if (mes < 1 || mes > 12 || dia < 1 || dia > 31) {
        return false;
    }

    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
        return false;
    }
    if (mes == 2) {
        bool anyoBissexto = (anyo % 4 == 0 && (anyo % 100 != 0 || anyo % 400 == 0));
        if (dia > (anyoBissexto ? 29 : 28)) {
            return false;
        }
    }

    return true;
}

void lerDadosComuns(string& nombre, string& apellidos, string& dni, string& fecha, string& domicilio, string& postal, string& localidad, string& telefono) {
      do {
        cout << "Introduzca el nombre: " << endl;
        getline(cin, nombre);
        if (isStringVaziaOuEspacos(nombre)) {
            cout << "Nombre no puede estar vacio. Introduzca de nuevo: " << endl;
        }
    } while (isStringVaziaOuEspacos(nombre));

    do {
        cout << "Introduzca los apellidos: " << endl;
        getline(cin, apellidos);
        if (isStringVaziaOuEspacos(apellidos)) {
            cout << "Apellidos no pueden estar vacios. Introduzca de nuevo: " << endl;
        }
    } while (isStringVaziaOuEspacos(apellidos));

    do {
        cout << "Introduzca el DNI o NIE: " << endl;
        getline(cin, dni);
        if (isStringVaziaOuEspacos(dni)) {
            cout << "DNI no puede estar vacio. Introduzca de nuevo: " << endl;
        }
    } while (isStringVaziaOuEspacos(dni));

    do {
        cout << "Introduzca la fecha de nacimiento (en formato dd/mm/aaaa): " << endl;
        getline(cin, fecha);
        if (!validarFecha(fecha) || isStringVaziaOuEspacos(fecha)) {
            cout << "Fecha de nacimiento invalida o vacia. Introduzca de nuevo en el formato dd/mm/aaaa: " << endl;
        }
    } while (!validarFecha(fecha) || isStringVaziaOuEspacos(fecha));

    do {
        cout << "Introduzca el domicilio: " << endl;
        getline(cin, domicilio);
        if (isStringVaziaOuEspacos(domicilio)) {
            cout << "Domicilio no puede estar vacio. Introduzca de nuevo: " << endl;
        }
    } while (isStringVaziaOuEspacos(domicilio));

    do {
        cout << "Introduzca el codigo postal: " << endl;
        getline(cin, postal);
        if (isStringVaziaOuEspacos(postal)) {
            cout << "Codigo postal no puede estar vacio. Introduzca de nuevo: " << endl;
        }
    } while (isStringVaziaOuEspacos(postal));

    do {
        cout << "Introduzca la localidad: " << endl;
        getline(cin, localidad);
        if (isStringVaziaOuEspacos(localidad)) {
            cout << "Localidad no puede estar vacia. Introduzca de nuevo: " << endl;
        }
    } while (isStringVaziaOuEspacos(localidad));

    do {
        cout << "Introduzca el numero de telefono: " << endl;
        getline(cin, telefono);
        if (isStringVaziaOuEspacos(telefono)) {
            cout << "Telefono no puede estar vacio. Introduzca de nuevo: " << endl;
        }
    } while (isStringVaziaOuEspacos(telefono));
}

void lerDadosFuncionario(string& departamento, string& categoria) {
    cout << "Introduzca el departamento del empleado:" << endl;
    getline(cin, departamento);

    cout << "Introduzca la categoría profesional del empleado: " << endl;
    getline(cin, categoria);
}



int main(){
     std::time_t tempo_atual = std::time(nullptr); 
    std::tm* tempo_local = std::localtime(&tempo_atual); 
    std::ostringstream oss;
    oss << std::put_time(tempo_local, "%d/%m/%Y");
    std::string data_formatada = oss.str();

    string nombre, apellidos, domicilio, localidad, postal, telefono, dni, fecha, categoria, departamento;
    int opcion;

    cout << "Bienvenido a Clinica Radiológica Aranguren. " "\n";
    cout << "Pulse 1 para introducir los datos de un paciente o pulse 2 para introducir los datos de un empleado: " "\n";
    cin >> opcion;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (opcion == 1){//paciente
        
        lerDadosComuns(nombre, apellidos, dni, fecha, domicilio, postal, localidad, telefono);

   Paciente paciente(nombre, apellidos, dni, fecha, domicilio, localidad, postal, telefono);

    ofstream archivo("pacientes.txt", ios::app);
   if(archivo.is_open()){
    archivo << "Paciente con DNI/NIE: " << paciente.getDNI() << "\n";
    archivo << "Nombre y apellidos: " << paciente.getNombre() << " " << paciente.getApellidos() << "\n";
    archivo << "Fecha de nacimiento: " << paciente.getFechaNacimiento() << "\n";
    archivo << "Domicilio: " << paciente.getDomicilio() << "\n";
    archivo << "C. P.: " << paciente.getPostal() << "; Localidad: " << paciente.getLocalidad() << "\n";
    archivo << "Nº Teléfono: " << paciente.getTelefono() << "\n";
    archivo << "_________________________________________________\n";
    archivo.close();
    cout << "Los datos del paciente se han almacenado correctamente en el archivo 'pacientes.txt'." << endl;
} else {
    cout << "Error al abrir el archivo 'pacientes.txt'." << endl;
}
}else if (opcion == 2){ //empleado
       
        lerDadosComuns(nombre, apellidos, dni, fecha, domicilio, postal, localidad, telefono);

        lerDadosFuncionario(departamento, categoria);


    Empleado empleado(nombre, apellidos, dni, fecha, domicilio, localidad, postal, telefono, departamento, categoria);


    ofstream archivo("empleados.txt", ios::app);
   if(archivo.is_open()){
    archivo << "Empleado con DNI/NIE: " << empleado.getDNI() << "\n";
    archivo << "Nombre y apellidos: " << empleado.getNombre() << " " << empleado.getApellidos() << "\n";
    archivo << "Fecha de nacimiento: " << empleado.getFechaNacimiento() << "\n";
    archivo << "Domicilio: " << empleado.getDomicilio() << "\n";
    archivo << "C. P.: " << empleado.getPostal() << "; Localidad: " << empleado.getLocalidad() << "\n";
    archivo << "Nº Teléfono: " << empleado.getTelefono() << "\n";
    archivo << "Departamento: " << empleado.getDepartamento() << "\n";
    archivo << "Categoria profesional: " << empleado.getCategoria() << "\n";
    archivo << "_________________________________________________\n";
    archivo.close();
    cout << "Los datos del empleado se han almacenado correctamente en el archivo 'empleados.txt'." << endl;
} else {
    cout << "Error al abrir el archivo 'empleados.txt'." << endl;
}
} else { 
    cout << "Opcion no valida. Intente una vez mas. " << endl;
}
return 0;
}