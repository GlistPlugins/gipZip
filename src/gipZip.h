/*
 * gipZip.h
 *
 *  Created on: 19 Aðu 2021
 *      Author: yavuzbilginoglu
 */

#ifndef SRC_GIPZIP_H_
#define SRC_GIPZIP_H_

#include "gBasePlugin.h"
#include "zip.h"
#include "unzip.h"
#include "minizip.c"

class gipZip : public gBasePlugin{
public:

	gipZip();
	virtual ~gipZip();

	bool open(std::string fullPath);
	bool openzip(std::string zipPath);
	bool closeZip(gipZip zip);

	bool addFile(gipZip zip, std::string filePath);
	bool closeFile(gipZip zipFile);

	std::vector<std::string> getFileList();


private:
	std::string fullpath, directory, filepath, extractpath,zippath;
	std::string getDirName(const std::string& fullPath);
	std::string getFileName(const std::string& fullPath);
	zipFile zip;
	zipFile zipFile;
	unzFile unzip;
};
#endif /* SRC_GIPEMPTY_H_ */
