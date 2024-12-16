#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>

#define FILENAME "contador.txt"

std::mutex file_mutex;

void actualizarArchivo(const std::string& columna, int delay) {
    while (true) {
        std::lock_guard<std::mutex> guard(file_mutex);
        std::fstream file(FILENAME, std::ios::in | std::ios::out);

        if (!file.is_open()) {
            std::cerr << "Error al abrir el archivo\n";
            exit(EXIT_FAILURE);
        }

        int contador;
        file >> contador;
        file.clear();
        file.seekp(0);

        if (columna == "1") {
            std::cout << "Columna 1 | Ri = " << contador << "\n";
        } else {
            std::cout << "\t\tColumna 2 | Ri = " << contador << "\n";
        }

        contador++;

        file << contador << "\n";
        file.flush();

        if (columna == "1") {
            std::cout << "Columna 1 | Wi = " << contador << "\n";
        } else {
            std::cout << "\t\tColumna 2 | Wi = " << contador << "\n";
        }

        file.close();
        std::this_thread::sleep_for(std::chrono::seconds(delay));
    }
}

int main() {
    // Crear el archivo inicial con valor 0
    std::ofstream file(FILENAME);
    if (!file.is_open()) {
        std::cerr << "Error al crear el archivo\n";
        exit(EXIT_FAILURE);
    }
    file << "0\n";
    file.close();

    // Crear dos hilos
    std::thread thread1(actualizarArchivo, "1", 2);
    std::thread thread2(actualizarArchivo, "2", 3);

    thread1.join();
    thread2.join();

    return 0;
}
