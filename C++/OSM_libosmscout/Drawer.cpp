// #include <Drawer.h>
// #include <osmscout/db/Database.h>
// #include <osmscout/feature/ConstructionYearFeature.h>
// #include <osmscoutmap/MapService.h>
// #include <osmscoutmapqt/MapPainterQt.h>

// #include <QPixmap>
// #include <iostream>

///*
//  Demos/DrawMapQt ../maps/Dortmund ../stylesheets/standard.oss 1000
//  800 51.514 7.465 40000 test.png
//*/

// static const double MIN_YEAR = 1800;
// static const double MAX_YEAR = 2020;

// class ConstructionProcessor : public osmscout::FillStyleProcessor {
//  private:
//   osmscout::NameFeatureLabelReader labelReader;
//   osmscout::ConstructionYearFeatureValueReader reader;

// public:
//  explicit ConstructionProcessor(const osmscout::TypeConfig& typeConfig)
//      : labelReader(typeConfig), reader(typeConfig) {}

//  osmscout::FillStyleRef Process(
//      const osmscout::FeatureValueBuffer& features,
//      const osmscout::FillStyleRef& fillStyle) const override {
//    const osmscout::ConstructionYearFeatureValue* value =
//        reader.GetValue(features);
//    if (value != nullptr) {
//      std::cout << labelReader.GetLabel(features) << ": "
//                << value->GetStartYear() << "-" << value->GetEndYear()
//                << std::endl;
//      if (value->GetStartYear() >= MIN_YEAR &&
//          value->GetStartYear() <= MAX_YEAR) {
//        double factor =
//            (value->GetStartYear() - MIN_YEAR) / (MAX_YEAR - MIN_YEAR + 1);
//        auto customStyle = std::make_shared<osmscout::FillStyle>();

//        customStyle->SetFillColor(osmscout::Color(factor, 0.0, 0.0));

//        return customStyle;
//      }
//    }
//    return fillStyle;
//  }
//};

// class AddressProcessor : public osmscout::FillStyleProcessor {
//  private:
//   osmscout::NameFeatureLabelReader labelReader;
//   osmscout::AddressFeatureValueReader reader;

// public:
//  explicit AddressProcessor(const osmscout::TypeConfig& typeConfig)
//      : labelReader(typeConfig), reader(typeConfig) {}

//  osmscout::FillStyleRef Process(
//      const osmscout::FeatureValueBuffer& features,
//      const osmscout::FillStyleRef& fillStyle) const override {
//    const osmscout::AddressFeatureValue* value = reader.GetValue(features);
//    if (value != nullptr) {
//      std::cout << labelReader.GetLabel(features) << ": " <<
//      value->GetAddress()
//                << std::endl;
//      size_t addressNumber;
//      if (osmscout::StringToNumber(value->GetAddress(), addressNumber)) {
//        auto customStyle = std::make_shared<osmscout::FillStyle>();
//        if (addressNumber % 2 == 0) {
//          customStyle->SetFillColor(osmscout::Color::BLUE);
//        } else {
//          customStyle->SetFillColor(osmscout::Color::GREEN);
//        }
//        return customStyle;
//      } else {
//        auto customStyle = std::make_shared<osmscout::FillStyle>();
//        customStyle->SetFillColor(osmscout::Color::RED);
//        return customStyle;
//      }
//    }
//    return fillStyle;
//  }
//};
