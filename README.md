# Penejelasan Beberapa Kode Program
<br>

## Fungsi fwrite()
jadi fwrite ini digunakan untuk menulis record (dalam urutan byte) ke dalam file. Record dapat berupa array atau structure

### Sintaks dari fwrite()

> #### fwrite( ptr, int size, int n, FILE *fp );

Jadi fungsi fwrite ini membutuhkan 4 parameter
1. **ptr** : ptr ini adalah referensi/merujuk dari array / structure yang disimpan dalam memori
2. **size** : size ini adalah total angka dalam bytes yang ingin kita tulis.
	 Jadi contoh, misalkan kita memberi nilai pada parameter ini angka 4, berarti kita ingin menulis
	 sebanyak 4 bytes
3. **n** : n ini maksudnya, berapa kali sebuah record itu akan menulis, misalkan pada parameter
	ke tiga ini kita menulis 1, berarti kita ingin sebuar record itu menulis hanya sekali saja
4. **File** * : adalah file di mana record akan ditulis dalam mode biner.
<br>

## Fungsi fread()

fungsi fread ini digunakan untuk membaca byte dari sebuah file.

### Sintaks dari fwrite()

> #### fread( ptr, int size, int n, FILE *fp );

Jadi fungsi fread ini membutuhkan 4 parameter
1. **ptr** : ptr ini adalah referensi/merujuk ke sebuah array/structure dimana
	data akan disimpan setelah kita membaca sebuah file.
2. **size** : size ini adalah total angka dalam bytes yang ingin kita baca.
3. **n** : n ini maksudnya, berapa kali sebuah record itu akan menulis
4. **File** * : adalah file di mana record akan dibaca
