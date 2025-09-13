import java.io.*;

// A preprocesszor használható a C++ fordítótól külön is tetszőleges szöveges
// állományon, akár más programozási nyelvek forráskódján is.
//
// cpp -P main.java

#define MESSAGE "Hello world!"
#define PRINT_MESSAGE(m) System.out.println(m)

public class main {
	public static void main(String[] args) {
		PRINT_MESSAGE(MESSAGE);
	}
}
