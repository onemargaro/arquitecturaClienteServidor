import java.net.*;
import java.io.*;
import java.security.*;
import javax.crypto.*;

public class Servidor06Cifrado
{
	public static void main(String a[]) throws Exception
	{
		ServerSocket serverSocket = null;
		Socket socket = null;
		// Peticion es lo que envia el Cliente
		byte peticion[] = new byte[1000];

		System.out.println( "Generando la llave en el Servidor..." );
		KeyGenerator keyGen = KeyGenerator.getInstance("DES");
		keyGen.init(56);
		Key llave = keyGen.generateKey();
		System.out.println( "llave=" + llave );
		System.out.println( "Llave generada!" );

		ObjectOutput out = new ObjectOutputStream(new FileOutputStream("llave.ser"));
		out.writeObject( llave );
		out.close();

		try
		{
			System.out.println("Escuchando por el puerto 8000");
			serverSocket = new ServerSocket(8000); 
		}
		catch(IOException e)
		{
			System.out.println("java.io.IOException generada");
			e.printStackTrace();
		}

		System.out.println("Esperando a que los clientes se conecten...");
		while(true)
		{
			try
			{
				socket = serverSocket.accept();
				System.out.println("Se conecto un cliente: " + socket.getInetAddress().getHostName());
				// Como ya hay socket, obtengo los flujos asociados a este
				DataInputStream dis = new DataInputStream( socket.getInputStream() );
				DataOutputStream dos = new DataOutputStream( socket.getOutputStream() );
				// Despues de la conexion, Servidor y Cliente deben ponerse de acuerdo
				// para ver quien escribe primero y entonces el otro debe leer
				BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
				// Como el Cliente escribe, yo debo leer
				int indice = 0;
				byte valor = 0;
				while( (valor = dis.readByte()) != 10 )
				{
					System.out.println( "valor=" + valor );
					peticion[ indice ] = (byte)valor;
					indice++;
				}
				// peticion = dis.read();
				byte arreglo[] = new byte[ indice ];
				for( int i=0; i < indice; i++ )
				{
					arreglo[ i ] = peticion[ i ];
				}
				System.out.println("El mensaje que me envio el cliente es: " + arreglo );
				bytesToBits( arreglo );
				Cipher cifrar = Cipher.getInstance("DES");
				cifrar.init(Cipher.DECRYPT_MODE, llave);
				byte[] newPlainText = cifrar.doFinal( arreglo );
				System.out.println( "El argumento DESENCRIPTADO es:" );
				System.out.println( new String(newPlainText, "UTF8") );
				dos.close();
				dis.close();
				socket.close();
			}
			catch(IOException e)
			{
				System.out.println("java.io.IOException generada");
				e.printStackTrace();
			}
		}
	}

	public static void bytesToBits( byte[] texto )
	{
		StringBuilder stringToBits = new StringBuilder();
		for( int i=0; i < texto.length; i++ )
		{
			StringBuilder binary = new StringBuilder();
			byte b = texto[i];
			int val = b;
			for( int j = 0; j < 8; j++ )
			{
				binary.append( (val & 128) == 0 ? 0 : 1 );
				val <<= 1;
			}
			System.out.println( (char)b + " \t " + b + " \t " + binary );
			stringToBits.append( binary );
		}
		System.out.println( "El mensaje completo en bits es:" + stringToBits );
	}
}

