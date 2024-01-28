#include <bits/stdc++.h>
using namespace std;

vector<vector<float>> add(const vector<vector<float>> &A, const vector<vector<float>> &B){

    int n = A.size(), m = A[0].size();
    vector<vector<float>> result(n, vector<float>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

vector<vector<float>> subtract(const vector<vector<float>> &A, const vector<vector<float>> &B){

    int n = A.size(), m = A[0].size();
    vector<vector<float>> result(n, vector<float>(m));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

// T(N) = 8T(N/2) + O(N2)  ==> T(N) same as the naive method and taking extra space
vector<vector<float>> matrixMultiply(const vector<vector<float>> &A, const vector<vector<float>> &B){

    int n1 = A.size();
    int n2 = B.size();

    if (n1 != n2){
        cerr << "\nError: enter vaild Matrices\n ";
        return {};
    }

    vector<vector<float>> c(n1, vector<float>(n1, 0));

    if (n1 == 1){
        c[0][0] = A[0][0] * B[0][0];
        return c;
    } // base case

    int v = log2(n1);

    if (pow(2, v) != n1){
        n1 = pow(2, v + 1);
    } // padding for matrix of size other than 2 powers

    int si = n1 / 2;

    vector<vector<float>> a00(si, vector<float>(si, 0)), a01(si, vector<float>(si, 0)), a10(si, vector<float>(si, 0)), a11(si, vector<float>(si, 0));
    vector<vector<float>> b00(si, vector<float>(si, 0)), b01(si, vector<float>(si, 0)), b10(si, vector<float>(si, 0)), b11(si, vector<float>(si, 0));

    for(int i = 0; i < si; i++){
        for(int j = 0; j < si; j++){

            a00[i][j] = A[i][j];
            b00[i][j] = B[i][j];
            if (j + si < n2){
                a01[i][j] = A[i][j + si];
                b01[i][j] = B[i][j + si];
            }
            if (i + si < n2){
                a10[i][j] = A[si + i][j];
                b10[i][j] = B[si + i][j];
            }
            if (j + si < n2 && i + si < n2){
                a11[i][j] = A[i + si][j + si];
                b11[i][j] = B[i + si][j + si];
            }
        }
    }

    vector<vector<float>> c_00 = add(matrixMultiply(a00, b00), matrixMultiply(a01, b10));
    vector<vector<float>> c_01 = add(matrixMultiply(a00, b01), matrixMultiply(a01, b11));
    vector<vector<float>> c_10 = add(matrixMultiply(a10, b00), matrixMultiply(a11, b10));
    vector<vector<float>> c_11 = add(matrixMultiply(a10, b01), matrixMultiply(a11, b11));

    for(int i = 0; i < si; i++){
        for(int j = 0; j < si; j++){

            c[i][j] = c_00[i][j];

            if (j + si < n2){
                c[i][j + si] = c_01[i][j];
            }
            if (i + si < n2){
                c[si + i][j] = c_10[i][j];
            }
            if (j + si < n2 && i + si < n2){
                c[i + si][j + si] = c_11[i][j];
            }
        }
    }

    return c;
}

// T(N) = 7T(N/2) + O(N2)
vector<vector<float>> strassen(const vector<vector<float>> &A, const vector<vector<float>> &B){

    int n1 = A.size();
    int n2 = B.size();

    if (n1 != n2){
        cerr << "\nError: enter vaild Matrices\n ";
        return {};
    }

    vector<vector<float>> c(n1, vector<float>(n1, 0));

    if (n1 == 1){
        c[0][0] = A[0][0] * B[0][0];
        return c;
    } // base case

    int v = log2(n1);
    if (pow(2, v) != n1){
        n1 = pow(2, v + 1);
    } // padding for matrix of size other than 2 powers

    int si = n1 / 2;

    vector<vector<float>> a00(si, vector<float>(si, 0)), 
                            a01(si, vector<float>(si, 0)), 
                            a10(si, vector<float>(si, 0)), 
                            a11(si, vector<float>(si, 0));
    vector<vector<float>> b00(si, vector<float>(si, 0)),
                            b01(si, vector<float>(si, 0)), 
                            b10(si, vector<float>(si, 0)), 
                            b11(si, vector<float>(si, 0));

    for (int i = 0; i < si; i++){
        for (int j = 0; j < si; j++){

            a00[i][j] = A[i][j];
            b00[i][j] = B[i][j];

            if (j + si < n2){
                a01[i][j] = A[i][j + si];
                b01[i][j] = B[i][j + si];
            }

            if (i + si < n2){
                a10[i][j] = A[si + i][j];
                b10[i][j] = B[si + i][j];
            }

            if (j + si < n2 && i + si < n2){
                a11[i][j] = A[i + si][j + si];
                b11[i][j] = B[i + si][j + si];
            }
        }
    }

    vector<vector<float>> p1 = strassen(a00, subtract(b01, b11));
    vector<vector<float>> p2 = strassen(add(a00, a01), b11);
    vector<vector<float>> p3 = strassen(add(a10, a11), b00);
    vector<vector<float>> p4 = strassen(a11, subtract(b10, b00));
    vector<vector<float>> p5 = strassen(add(a00, a11), add(b00, b11));
    vector<vector<float>> p6 = strassen(subtract(a01, a11), add(b10, b11));
    vector<vector<float>> p7 = strassen(subtract(a00, a10), add(b00, b01));

    vector<vector<float>> c_00 = subtract(add(add(p5, p4), p6), p6);
    vector<vector<float>> c_01 = add(p1, p2);
    vector<vector<float>> c_10 = add(p3, p4);
    vector<vector<float>> c_11 = subtract(add(p1, p5), add(p3, p7));

    for (int i = 0; i < si; i++){
        for (int j = 0; j < si; j++){

            c[i][j] = c_00[i][j];

            if (j + si < n2){
                c[i][j + si] = c_01[i][j];
            }

            if (i + si < n2){
                c[si + i][j] = c_10[i][j];
            }

            if (j + si < n2 && i + si < n2){
                c[i + si][j + si] = c_11[i][j];
            }
        }
    }

    return c;
}

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while (tt--){

        int n;
        cin >> n;
        vector<vector<float>> A(n, vector<float>(n)), B(n, vector<float>(n));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> A[i][j];
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> B[i][j];
            }
        }
        vector<vector<float>> C = strassen(A, B);

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << C[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}