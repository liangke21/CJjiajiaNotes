//MyProgram.cpp

import  ModuleA;

int main210201() {
	Bar22::f(); // OK
	Bar22::d(); // OK
	//Bar22::internal_f(); // Ill-formed: error C2065: 'internal_f': undeclared identifier

	return 0;
}