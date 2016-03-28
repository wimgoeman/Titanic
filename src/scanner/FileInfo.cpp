#include "FileInfo.h"

namespace titanic {
	namespace scanner {

		FileInfo::FileInfo(const std::string& filename) : _filename(filename)
		{
		}


		FileInfo::~FileInfo()
		{
		}

		const std::string&
		FileInfo::getFilename() const
		{
			return _filename;
		}

		void
		FileInfo::setFilename(const std::string& filename)
		{
			_filename = filename;
		}

		const std::string&
		FileInfo::getHash() const
		{
			return _hash;
		}

		void
		FileInfo::setHash(const std::string& hash)
		{
			_hash = hash;
		}

	}
}