/*
 * gipZip.cpp
 *
 *  Created on: 19 Aðu 2021
 *      Author: yavuzbilginoglu
 */
#include "gipZip.h"


gipZip::gipZip() {
	zip = NULL;
	zipFile = NULL;
	unzip = NULL;
}
gipZip::~gipZip() {

}
bool gipZip::open(std::string fullPath) {
	fullpath = fullPath;
	directory = getDirName(fullpath);

	if(fullpath == NULL) {
		gLogi("creating new zip");
		return zip = zipOpen(fullpath.c_str(), 0);
	} else {
		gLogi("unzipping!");
		return unzip = unzOpen(fullpath.c_str());
	}
}

bool gipZip::openzip(std::string zipPath) {
	return open(gGetZipsDir() + zipPath);
}
bool gipZip::addFile(gipZip zipFile, std::string fileName) {
	zip_fileinfo zi;
	zi.tmz_date.tm_sec = zi.tmz_date.tm_min = zi.tmz_date.tm_hour = zi.tmz_date.tm_mday = zi.tmz_date.tm_mon = zi.tmz_date.tm_year = 0;
	zi.dosDate = 0;
	zi.internal_fa = 0;
	zi.external_fa = 0;

	filepath = getFileName(fileName);
	return zipOpenNewFileInZip(zip, filepath.c_str(), &zi, NULL, 0, NULL, 0, "my comment", 0, Z_DEFAULT_COMPRESSION);
}

std::vector<std::string> gipZip::getFileList() {
	return minizip_list(fullpath.c_str());
}

bool gipZip::closeFile(gipZip zipFile) {
	//int32_t err = MZ_OK;
	if (zipFile == NULL) {
		gLogi("cant find file");
		return ZIP_PARAMERROR;
		}
	else return zipCloseFileInZip(zip);
}

bool gipZip::closeZip(gipZip zipFile) {
	if (zip == NULL) {
			gLogi("cant find zip");
			return ZIP_PARAMERROR;
		}
	else return zipClose(zip, "zip closed");
}

