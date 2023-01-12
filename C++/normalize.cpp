#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Converts a string to an integer
double str_to_double(string str) {
    stringstream ss(str);
    double result;
    ss >> result;
    return result;
}

// Converts a list of strings to a list of integers
void str_list_to_double(vector<string> &list1,vector<double> &list) {
    for (int i = 0; i < list1.size(); i++) {
        list.push_back(str_to_double(list1[i]));
    }
}
void print_matrix(vector<vector<vector<double>>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            for (int k = 0; k < matrix[i][j].size(); k++) {
                cout << matrix[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

// ...




int main() {
    // Open pic.ppm file in read mode
    ifstream file("../img/img_1.ppm");

    // Read in all lines from the file
    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    // Convert lines to a matrix of integers
    vector<vector<vector<double>>> matrix;
    for (int i = 3; i < lines.size(); i++) {
        vector<vector<double>> ligne;
        vector<string> raw1;
        vector<double> raw;
        vector<double> pixel;
        stringstream ss(lines[i]);
        string token;
        while (getline(ss, token, ' ')) {
            raw1.push_back(token);
        }
        str_list_to_double(raw1,raw);
        for (int j = 0; j < raw.size(); j++) {
            if (j % 3 == 0) {
                pixel.push_back(raw[j]);
            }
            if (j % 3 == 1) {
                pixel.push_back(raw[j]);
            }
            if (j % 3 == 2) {
                pixel.push_back(raw[j]);
                ligne.push_back(pixel);
                pixel.clear();
            }
        }
        matrix.push_back(ligne);
        cout << matrix.size() << endl;
    }

    // Write matrix to matrix.txt file
    ofstream f("matrix.txt");
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            for (int k = 0; k < matrix[i][j].size(); k++) {
                f << matrix[i][j][k] << " ";
            }
            f << endl;
        }
        f << endl;
    }
    f.close();

    // Create a new matrix with the rows 4 to 27
    vector<vector<vector<double>>> img;
    for (int i = 4; i < 28; i++) {
        vector<vector<double>> row;
        for (int j = 4; j < 28; j++) {
            row.push_back(matrix[i][j]);
        }
        img.push_back(row);
    }

    // Normalize the values in the img matrix
    int N = 24 * 24 * 3;
    double mu = 0;
    double sigma = 0;
    for (int i = 0; i < img.size(); i++) {
    for (int j = 0; j < img[i].size(); j++) {
        for (int k = 0; k < img[i][j].size(); k++) {
            mu += img[i][j][k] / N;
        }
    }
}

for (int i = 0; i < img.size(); i++) {
    for (int j = 0; j < img[i].size(); j++) {
        for (int k = 0; k < img[i][j].size(); k++) {
            sigma += (img[i][j][k] - mu) * (img[i][j][k] - mu);
        }
    }
}
sigma = sqrt(sigma / N);

for (int i = 0; i < img.size(); i++) {
    for (int j = 0; j < img[i].size(); j++) {
        for (int k = 0; k < img[i][j].size(); k++) {
            img[i][j][k] = (img[i][j][k] - mu) / max(sigma, 1 / sqrt(N));
        }
    }
}
print_matrix(img);
// Write img to img.txt file
ofstream f1("img.txt");
for (int i = 0; i < img.size(); i++) {
    for (int j = 0; j < img[i].size(); j++) {
        for (int k = 0; k < img[i][j].size(); k++) {
            f1 << img[i][j][k] << " ";
            }
        f1 << endl;
    }
    f1 << endl;
}
f1.close();
return 0;

}