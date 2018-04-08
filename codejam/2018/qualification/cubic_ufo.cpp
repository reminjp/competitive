#include <bits/stdc++.h>
using namespace std;

class Vector3 {
public:
	double x, y, z;
	Vector3();
	Vector3(double x, double y, double z);
	Vector3 operator-() const;
	Vector3& operator+=(const Vector3&);
};

inline Vector3::Vector3() { x = y = z = 0; }

inline Vector3::Vector3(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

inline Vector3 Vector3::operator-() const {
	return Vector3(-x, -y, -z);
}

inline Vector3& Vector3::operator+=(const Vector3& v) {
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
	return *this;
}

inline Vector3 operator+(const Vector3& t1, const Vector3& t2) { return Vector3(t1) += t2; }

typedef complex<double> P;
#define EPS (1e-9)
#define EQ(a, b) (abs((a) - (b)) < EPS)
#define PI (3.14159265358979323846)
#define SQRT2 (1.41421356237309504880)

void solve() {
	double a;
	cin >> a;
	vector<Vector3> r, cube = {Vector3(SQRT2 / 4.0, 0, SQRT2 / 4.0), Vector3(0, 1.0 / 2.0, 0), Vector3(-SQRT2 / 4.0, 0, SQRT2 / 4.0)};
	double small = 0, large = atan(SQRT2), m;
	while (!EQ(small, large)) {
		m = (small + large) / 2.0;
		r = cube;
		for (auto& e : r) {
			P v(e.x, e.y);
			e.x = v.real() * cos(m) - v.imag() * sin(m);
			e.y = v.real() * sin(m) + v.imag() * cos(m);
		}
		vector<Vector3> hexagon{-r[0] + r[1] + r[2], r[0] + r[1] + r[2], r[0] + -r[1] + r[2], r[0] + -r[1] + -r[2], -r[0] + -r[1] + -r[2], -r[0] + r[1] + -r[2]};
		double s = 0;
		for (int i = 0; i < hexagon.size(); i++) {
			s += abs(hexagon[i].z * hexagon[(i + 1) % hexagon.size()].x - hexagon[(i + 1) % hexagon.size()].z * hexagon[i].x) / 2.0;
		}
		if (s < a) {
			small = m;
		} else if (a < s) {
			large = m;
		}
	}
	cout << fixed << setprecision(9);
	for (auto e : r) {
		cout << e.x << " " << e.y << " " << e.z << endl;
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ":" << endl;
		solve();
	}
	return 0;
}
