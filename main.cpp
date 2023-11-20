#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

auto recursiveGetFileNamesByExtension =
					[]( const std::filesystem::path& _path,
	   					const std::string& _extension) {
	std::vector<std::string> _file_names;

	if (exists(_path)) {
		for (auto& it: std::filesystem::recursive_directory_iterator(_path)) {
			if (it.is_regular_file()) {
				if (!it.path().extension().compare(_extension)) {
					_file_names.push_back(it.path().filename().string());
				}
			}
		}
		return _file_names;
	} else {
		_file_names.emplace_back("This path not exist!");
		return _file_names;
	}
};

int main() {
	std::string path, extension;
	std::vector<std::string> file_names;
	std::cout << "Input path to directory for search:";
	std::getline(std::ws(std::cin), path);
	std::cout << "Now, input Extension for search:";
	std::cin >> extension;
	file_names = recursiveGetFileNamesByExtension(path, extension);

	if (!file_names.empty()) {
		for (auto& it: file_names) {
			std::cout << it << std::endl;
		}
	} else {
		std::cout << "No files finded!";
	}
}
