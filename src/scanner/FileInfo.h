#pragma once

#include <string>

namespace titanic {
	namespace scanner {

		class FileInfo
		{
		public:
			FileInfo(const std::string& filename);
			virtual ~FileInfo();

			const std::string&
				getFilename() const;

			void
				setFilename(const std::string& filename);

			const std::string&
				getHash() const;

			void
				setHash(const std::string& hash);

		private:
			std::string _filename;
			std::string _hash;
		};

	}
}