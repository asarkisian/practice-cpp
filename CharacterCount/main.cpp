#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;


int main(int argc, char** argv){

    string content = "";
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

    do{
        a = b = c = d = e = f = g = h = i = j = k = l = m = n = o = p = q = r = s = t = u = v = w = x = y = z = 0;

        cout << "Enter a string or \'X\' to exit: ";
        getline(cin, content);

        if(content == "X"){
            break;
        }

        for(unsigned int count=0; count<content.length(); count++){
            content[count] = tolower(content[count]);

            if(content[count] == 'a'){
                a += 1;
            }
            else if(content[count] == 'b'){
                b += 1;
            }
            else if(content[count] == 'c'){
                c += 1;
            }
            else if(content[count] == 'd'){
                d += 1;
            }
            else if(content[count] == 'e'){
                e += 1;
            }
            else if(content[count] == 'f'){
                f += 1;
            }
            else if(content[count] == 'g'){
                g += 1;
            }
            else if(content[count] == 'h'){
                h += 1;
            }
            else if(content[count] == 'i'){
                i += 1;
            }
            else if(content[count] == 'j'){
                j += 1;
            }
            else if(content[count] == 'k'){
                k += 1;
            }
            else if(content[count] == 'l'){
                l += 1;
            }
            else if(content[count] == 'm'){
                m += 1;
            }
            else if(content[count] == 'n'){
                n += 1;
            }
            else if(content[count] == 'o'){
                o += 1;
            }
            else if(content[count] == 'p'){
                p += 1;
            }
            else if(content[count] == 'q'){
                q += 1;
            }
            else if(content[count] == 'r'){
                r += 1;
            }
            else if(content[count] == 's'){
                s += 1;
            }
            else if(content[count] == 't'){
                t += 1;
            }
            else if(content[count] == 'u'){
                u += 1;
            }
            else if(content[count] == 'v'){
                v += 1;
            }
            else if(content[count] == 'w'){
                w += 1;
            }
            else if(content[count] == 'x'){
                x += 1;
            }
            else if(content[count] == 'y'){
                y += 1;
            }
            else if(content[count] == 'z'){
                z += 1;
            }
        }

        if(a > 0){
            cout << "A: " << a << endl;
        }
        if(b > 0){
            cout << "B: " << b << endl;
        }
        if(c > 0){
            cout << "C: " << c << endl;
        }
        if(d > 0){
            cout << "D: " << d << endl;
        }
        if(e > 0){
            cout << "E: " << e << endl;
        }
        if(f > 0){
            cout << "F: " << f << endl;
        }
        if(g > 0){
            cout << "G: " << g << endl;
        }
        if(h > 0){
            cout << "H: " << h << endl;
        }
        if(i > 0){
            cout << "I: " << i << endl;
        }
        if(j > 0){
            cout << "J: " << j << endl;
        }
        if(k > 0){
            cout << "K: " << k << endl;
        }
        if(l > 0){
            cout << "L: " << l << endl;
        }
        if(m > 0){
            cout << "M: " << m << endl;
        }
        if(n > 0){
            cout << "N: " << n << endl;
        }
        if(o > 0){
            cout << "O: " << o << endl;
        }
        if(p > 0){
            cout << "P: " << p << endl;
        }
        if(q > 0){
            cout << "Q: " << q << endl;
        }
        if(r > 0){
            cout << "R: " << r << endl;
        }
        if(s > 0){
            cout << "S: " << s << endl;
        }
        if(t > 0){
            cout << "T: " << t << endl;
        }
        if(u > 0){
            cout << "U: " << u << endl;
        }
        if(v > 0){
            cout << "V: " << v << endl;
        }
        if(w > 0){
            cout << "W: " << w << endl;
        }
        if(x > 0){
            cout << "X: " << x << endl;
        }
        if(y > 0){
            cout << "Y: " << y << endl;
        }
        if(z > 0){
            cout << "Z: " << z << endl;
        }

    }while(true);



    return(0);
}
