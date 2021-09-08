/*
 * gipZip.h
 *
 *  Created on: 19 A�u 2021
 *      Author: yavuzbilginoglu
 */

#ifndef SRC_GIPZIP_H_
#define SRC_GIPZIP_H_

#include "gBasePlugin.h"
#include "zip.h"
#include "unzip.h"


class gipZip : public gBasePlugin{
public:

	gipZip();
	virtual ~gipZip();

	bool open(std::string fullPath);
	bool openzip(std::string zipPath);
	bool close();

	bool addFile(std::string filePath);

//	std::vector<std::string> getFileList();


private:
	std::string fullpath, directory, filepath, extractpath,zippath;
	std::string getDirName(const std::string& fullPath);
	std::string getFileName(const std::string& fullPath);
	zipFile zip;
	unzFile unzip;
};
#endif /* SRC_GIPEMPTY_H_ */
