#include "VersionInfo.h"


VersionInfo::VersionInfo() {

}

VersionInfo::~VersionInfo() {

}

bool VersionInfo::operator>(VersionInfo &op) {
	return this->build > op.build;
}

bool VersionInfo::operator<(VersionInfo &op) {
	return this->build < op.build;
}

bool VersionInfo::operator==(VersionInfo &op) {
	return this->build == op.build;
}

bool VersionInfo::operator!=(VersionInfo &op) {
	return this->build != op.build;
}

