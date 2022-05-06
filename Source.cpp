#include "AdaptiveHuffman.h"
#include <chrono>

struct Timer {
public:
	Timer() = default;
	void Start() {
		start = std::chrono::high_resolution_clock::now();
	}
	void Stop() {
		stop = std::chrono::high_resolution_clock::now();
	}
	float time() {
		elapsedTime = std::chrono::duration<float, std::milli>(stop - start).count();
		return elapsedTime;
	}
private:
	float elapsedTime{};
	std::chrono::time_point<std::chrono::high_resolution_clock> start, stop;
};


int main() {
	auto timer = Timer();
	std::fstream output1(R"(..\AdaptiveHuffmanCoding\testFile3.txt)", std::ios_base::out | std::ios_base::binary);
	std::fstream input(R"(..\AdaptiveHuffmanCoding\testFile.txt)", std::ios_base::in | std::ios_base::binary);
	auto output = stl::OpenOutputBitFile(R"(..\AdaptiveHuffmanCoding\testFile2.txt)");
	auto input1 = stl::OpenInputBitFile(R"(..\AdaptiveHuffmanCoding\testFile2.txt)");

	try {
		std::cout << "compression started....\n";
		timer.Start();
		compressFile(input, output);
		timer.Stop();
		printf("normal Huffman time = %f milliseconds", timer.time());
		std::cout << "\nFile compression complete\n";
		stl::closeOutputBitFile(output);
		/*std::cout << "Expansion started....\n";
		ExpandFile(input1, output1);
		std::cout << "File expansion complete\n";
		stl::closeInputBitFile(input1);*/
	}
	catch (stl::FileError const& error) {
		std::cout << error.what();
		std::cout << "File compression failed\n";
	}
	catch (...) {
		std::cout << "An error occurred during compression or expansion\n";
	}
}