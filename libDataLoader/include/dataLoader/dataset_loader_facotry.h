#pragma once
#include "dataset3RScan.h"
#include "datasetScanNet.h"
#include "datasetStereo.h"
#include "dataloader_3rscan.h"
#include "dataloader_scannet.h"
#include "dataloader_stereo.h"

namespace PSLAM {
    struct  DataLoaderFactory {
        static DatasetLoader_base *Make(
                const std::string &pth, INPUTE_TYPE inputeType = DATASET_DETECT) {
            DatasetLoader_base *output = nullptr;
            // detect datatype by checking file name

            if(inputeType == DATASET_DETECT){

                std::cerr << "detect data type: ";
                if(pth.find(".sens") != std::string::npos || pth.find("scene") != std::string::npos) {
                    inputeType = DATASET_SCANNET;
                    std::cerr << "ScanNet";
                } else if (pth.find("3RScan") != std::string::npos) {
                    inputeType = DATASET_3RSCAN;
                    std::cerr << "3RScan";
                } else if (pth.find("stereo") != std::string::npos) {
                    inputeType = DATASET_STEREO;
                    std::cerr << "Stereo\n";
                }
            }

            // Create dataloader
            switch (inputeType) {
                case DATASET_3RSCAN: {
                    auto path = pth.back() == '/'? pth : pth+"/";
                    auto database = std::make_shared<Scan3RDataset>(inputeType, path);
                    output = new DatasetLoader_3RScan(database);
                    break;
                }
                case DATASET_SCANNET: {
                    auto database = std::make_shared<ScanNetDataset>(inputeType, pth);
                    output = new DatasetLoader_ScanNet(database);
                    break;
                }
                case DATASET_STEREO: {
                    auto database = std::make_shared<StereoDataset>(inputeType, pth);
                    output = new DatasetLoader_Stereo(database);
                    break;
                }
                case DATASET_DETECT:
                    break;

            }
            return output;
        }
    };
}