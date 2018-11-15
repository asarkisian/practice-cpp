/////////////////////////////////////////////////////////////////////////////
#if !defined ___MANAGEMENT_H___
#define ___MANAGEMENT_H___
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "typedefs.h"
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
class DataManagement
{
public:
	DataManagement();
	~DataManagement();

	void addFiles(fileName_t f, std::string mode);
	void addRegistry(registryName_t r, std::string mode);

	fileName_t criticalFiles(uint_t elem_) const;
	fileName_t missingFiles(uint_t elem_) const;
	fileName_t corruptedFiles(uint_t elem_) const;

	registryName_t criticalRegistries(uint_t elem_) const;
	registryName_t missingRegistries(uint_t elem_) const;
	registryName_t corruptedRegistries(uint_t elem_) const;

	bool isMissingFilesEmpty() const;
	bool isMissingRegistriesEmpty() const;
	bool isCorruptedFilesEmpty() const;
	bool isCorruptedRegistriesEmpty() const;

	uint_t criticalFilesSize() const;
	uint_t criticalRegistriesSize() const;
	uint_t missingFilesSize() const;
	uint_t missingRegistriesSize() const;
	uint_t corruptedRegistriesSize() const;
	uint_t corruptedFilesSize() const;

private:
	std::vector<fileName_t>* my_criticalFiles;
	std::vector<registryName_t>* my_criticalRegistries;
	std::vector<fileName_t>* my_missingFiles;
	std::vector<fileName_t>* my_corruptedFiles;
	std::vector<registryName_t>* my_missingRegistries;
	std::vector<registryName_t>* my_corruptedRegistries;
};
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
#endif
/////////////////////////////////////////////////////////////////////////////