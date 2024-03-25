
var DataInfo=[{id:"cmu",name:"CMU",description:"-",link:"http://domedb.perception.cs.cmu.edu/",category:"Image",field:"3-D Estimation",task:"-",instances:"-",num:"1",tutorial:"-"},
{id:"human-3.6m",name:"Human 3.6M",description:"The Human3.6M dataset is one of the largest motion capture datasets, which consists of 3.6 million human poses and corresponding images captured by a high-speed motion capture system. There are 4 high-resolution progressive scan cameras to acquire video ...",link:"http://vision.imar.ro/human3.6m/description.php",category:"Image",field:"3-D Estimation",task:"3D_Human_Pose_Estimation,3D_Absolute_Human_Pose_Estimation,Human_action_generation",instances:"-",num:"2",tutorial:"-"},
{id:"apoloscape",name:"ApoloScape",description:"-",link:"http://apolloscape.auto/",category:"Image",field:"Autonomous Driving",task:"-",instances:"-",num:"3",tutorial:"https://capsulesbot.com/blog/2018/08/24/apolloscape-posenet-pytorch.html"},
{id:"cifar-10",name:"cifar-10",description:"The CIFAR-10 dataset (Canadian Institute for Advanced Research, 10 classes) is a subset of the Tiny Images dataset and consists of 60000 32x32 color images. The images are labelled with one of 10 mutually exclusive classes: airplane, automobile (but not ...",link:"https://www.cs.toronto.edu/~kriz/cifar.html",category:"Image",field:"Classification",task:"Image_Classification,Image_Generation,Graph_Classification",instances:"60000",num:"4",tutorial:"https://ermlab.com/en/blog/nlp/cifar-10-classification-using-keras-tutorial/"},
{id:"cifar-100",name:"cifar-100",description:"The CIFAR-100 dataset (Canadian Institute for Advanced Research, 100 classes) is a subset of the Tiny Images dataset and consists of 60000 32x32 color images. The 100 classes in the CIFAR-100 are grouped into 20 superclasses. There are 600 images per cla...",link:"https://www.cs.toronto.edu/~kriz/cifar.html",category:"Image",field:"Classification",task:"Image_Classification,Image_Generation,Few-Shot_Image_Classification",instances:"60000",num:"5",tutorial:"-"},
{id:"omniglot",name:"omniglot",description:"Omniglot is a large dataset of hand-written characters with 1623 characters and 20 examples for each character. These characters are collected based upon 50 alphabets from different countries. It contains both images and strokes data. Stroke data are coo...",link:"https://github.com/brendenlake/omniglot#python",category:"Image",field:"Classification",task:"Few-Shot_Image_Classification,Density_Estimation,Multi-Task_Learning",instances:"38300",num:"6",tutorial:"https://towardsdatascience.com/few-shot-learning-with-prototypical-networks-87949de03ccd"},
{id:"mnist",name:"mnist",description:"The MNIST database (Modified National Institute of Standards and Technology database) is a large collection of handwritten digits. It has a training set of 60,000 examples, and a test set of 10,000 examples. It is a subset of a larger NIST Special Databa...",link:"http://yann.lecun.com/exdb/mnist/",category:"Image",field:"Classification",task:"Image_Classification,Image_Generation,Domain_Adaptation",instances:"60000",num:"7",tutorial:"https://towardsdatascience.com/image-classification-in-10-minutes-with-mnist-dataset-54c35b77a38d"},
{id:"celeba",name:"celebA",description:"CelebFaces Attributes dataset contains 202,599 face images of the size 178×218 from 10,177 celebrities, each annotated with 40 binary labels indicating facial attributes like hair color, gender and age.",link:"http://mmlab.ie.cuhk.edu.hk/projects/CelebA.html",category:"Image",field:"Classification",task:"Image_Classification,Image_Generation,Face_Alignment",instances:"-",num:"8",tutorial:"-"},
{id:"svhn",name:"SVHN",description:"The Street View House Number (SVHN) is a digit classification benchmark dataset that contains 600000 32×32 RGB images of printed digits (from 0 to 9) cropped from pictures of house number plates. The cropped images are centered in the digit of interest,...",link:"http://ufldl.stanford.edu/housenumbers/",category:"Image",field:"Classification",task:"Image_Classification,Domain_Adaption,Semi-Supervised_Image_Classification",instances:"-",num:"9",tutorial:"-"},
{id:"street_style_dataset_of_matzen",name:"Street Style dataset of Matzen",description:"-",link:"http://streetstyle.cs.cornell.edu/",category:"Image",field:"Classification",task:"-",instances:"-",num:"10",tutorial:"-"},
{id:"pku_vehicleid",name:"PKU VehicleID (VehicleID)",description:"The “VehicleID” dataset contains CARS captured during the daytime by multiple real-world surveillance cameras distributed in a small city in China. There are 26,267 vehicles (221,763 images in total) in the entire dataset. Each image is attached with...",link:"https://pkuml.org/resources/pku-vehicleid.html",category:"Image",field:"Classification",task:"Vehicle_Re-Identification",instances:"-",num:"11",tutorial:"-"},
{id:"the_in-shop_clothes",name:"The In-shop Clothes",description:"-",link:"http://mmlab.ie.cuhk.edu.hk/projects/DeepFashion/InShopRetrieval.html",category:"Image",field:"Classification",task:"-",instances:"-",num:"12",tutorial:"-"},
{id:"taskonomy",name:"Taskonomy",description:"Taskonomy provides a large and high-quality dataset of varied indoor scenes. Complete pixel-level geometric information via aligned meshes.  Semantic information via knowledge distillation from ImageNet, MS COCO, and MIT Places.  Globally consistent c...",link:"http://taskonomy.stanford.edu/",category:"Image",field:"Depth Estimation",task:"Depth_Estimation,Surface_Normals_Estimation",instances:"-",num:"13",tutorial:"-"},
{id:"cuhk_face_sketch_database",name:"CUHK Face Sketch Database (CUFS)",description:"-",link:"http://www.ee.cuhk.edu.hk/~xgwang/datasets.html",category:"Image",field:"Face Sketch",task:"-",instances:"-",num:"14",tutorial:"-"},
{id:"chestx-ray8",name:"ChestX-ray8",description:"ChestX-ray8 is a medical imaging dataset which comprises 108,948 frontal-view X-ray images of 32,717 (collected from the year of 1992 to 2015) unique patients with the text-mined eight common disease labels, mined from the text radiological reports via N...",link:"https://www.kaggle.com/nih-chest-xrays/data",category:"Image",field:"Medical Classification",task:"Image_Classification,Computed_Tomography(CT)",instances:"-",num:"15",tutorial:"-"},
{id:"kitti",name:"kitti",description:"KITTI (Karlsruhe Institute of Technology and Toyota Technological Institute) is one of the most popular datasets for use in mobile robotics and autonomous driving. It consists of hours of traffic scenarios recorded with a variety of sensor modalities, in...",link:"http://www.cvlibs.net/datasets/kitti/",category:"Image",field:"Object Detection",task:"Object_Detection,Semantice_Segmentation,Image_Super-Resolution",instances:">100 GB of data",num:"16",tutorial:"https://github.com/joseph-zhang/KITTI-TorchLoader"},
{id:"pascal_voc_2012",name:"pascal voc 2012",description:"-",link:"http://host.robots.ox.ac.uk/pascal/VOC/voc2012/",category:"Image",field:"Object Detection",task:"-",instances:"-",num:"17",tutorial:"-"},
{id:"cityscapes",name:"Cityscapes",description:"Cityscapes is a large-scale database which focuses on semantic understanding of urban street scenes. It provides semantic, instance-wise, and dense pixel annotations for 30 classes grouped into 8 categories (flat surfaces, humans, vehicles, constructions...",link:"https://www.cityscapes-dataset.com/",category:"Image",field:"Object Detection",task:"Image_Generation,Semantic_Segmentation,Image-to-Image_Translation",instances:"25000",num:"18",tutorial:"-"},
{id:"aflw",name:"AFLW",description:"The Annotated Facial Landmarks in the Wild (AFLW) is a large-scale collection of annotated face images gathered from Flickr, exhibiting a large variety in appearance (e.g., pose, expression, ethnicity, age, gender) as well as general imaging and environm...",link:"https://www.tugraz.at/institute/icg/research/team-bischof/lrs/downloads/aflw/",category:"Image",field:"Object Detection",task:"Face_Alignment,Facial_Landmark's_Detection,Low-Light_Image_Enhancement",instances:"-",num:"19",tutorial:"-"},
{id:"caltech_101",name:"Caltech 101",description:"The Caltech101 dataset contains images from 101 object categories (e.g., “helicopter”, “elephant” and “chair” etc.) and a background category that contains the images not from the 101 object categories. For each object category, there are abo...",link:"http://www.vision.caltech.edu/Image_Datasets/CaltechPedestrians/",category:"Image",field:"Object Detection",task:"Fine-Grained_Image_Classification,Semi-Supervised_Image_Classificatino,Density_Estimation",instances:"9146",num:"20",tutorial:"-"},
{id:"caltech_256",name:"Caltech 256",description:"Caltech-256 is an object recognition dataset containing 30,607 real-world images, of different sizes, spanning 257 classes (256 object classes and an additional clutter class). Each class is represented by at least 80 images. The dataset is a superset of...",link:"https://authors.library.caltech.edu/7694/",category:"Image",field:"Object Detection",task:"Few-Shot_Image_Classification,Semi-Supervised_Image_Classification",instances:"30607",num:"21",tutorial:"-"},
{id:"amazon",name:"Amazon",description:"-",link:"https://docs.aws.amazon.com/rekognition/latest/customlabels-dg/cd-create-dataset.html",category:"Image",field:"Object Detection",task:"-",instances:"-",num:"22",tutorial:"-"},
{id:"nlpr",name:"NLPR",description:"The NLPR dataset for salient object detection consists of 1,000 image pairs captured by a standard Microsoft Kinect with a resolution of 640×480. The images include indoor and outdoor scenes (e.g., offices, campuses, streets and supermarkets).",link:"https://www.abbreviationfinder.org/ko/acronyms/nlpr.html",category:"Image",field:"Object Detection",task:"RGB-D_Salient_Object_Detection",instances:"-",num:"23",tutorial:"-"},
{id:"coco",name:"coco",description:"The MS COCO (Microsoft Common Objects in Context) dataset is a large-scale object detection, segmentation, key-point detection, and captioning dataset. The dataset consists of 328K images. Splits: The first version of MS COCO dataset was released in 2...",link:"https://cocodataset.org/#home",category:"Image",field:"Object Recognition",task:"Pose_Estimation,Object_Detection,Semantic_Segmentation",instances:"2500000",num:"24",tutorial:"https://medium.com/fullstackai/how-to-train-an-object-detector-with-your-own-coco-dataset-in-pytorch-319e7090da5"},
{id:"imagenet",name:"imagenet",description:"The ImageNet dataset contains 14,197,122 annotated images according to the WordNet hierarchy. Since 2010 the dataset is used in the ImageNet Large Scale Visual Recognition Challenge (ILSVRC), a benchmark in image classification and object detection. The ...",link:"http://image-net.org/about-overview",category:"Image",field:"Object Recognition",task:"Image_Classification,Image_Generation,Few-Shot_Learning",instances:"14197122",num:"25",tutorial:"-"},
{id:"sun",name:"sun",description:"-",link:"https://vision.princeton.edu/projects/2010/SUN/",category:"Image",field:"Object Recognition",task:"-",instances:"131,067",num:"26",tutorial:"-"},
{id:"lsun",name:"lsun",description:"The Large-scale Scene Understanding (LSUN) challenge aims to provide a different benchmark for large-scale scene classification and understanding. The LSUN classification dataset contains 10 scene categories, such as dining room, bedroom, chicken, outdoo...",link:"https://www.yf.io/p/lsun",category:"Image",field:"Saliency Detection",task:"Image_Generation",instances:"-",num:"27",tutorial:"-"},
{id:"replica",name:"Replica",description:"The Replica Dataset is a dataset of high quality reconstructions of a variety of indoor spaces. Each reconstruction has clean dense geometry, high resolution and high dynamic range textures, glass and mirror surface information, planar segmentation as we...",link:"https://github.com/facebookresearch/Replica-Dataset",category:"Image",field:"Scene Generation",task:"Domain_Adaption,Visual_Navigation,Scene_Generation",instances:"-",num:"28",tutorial:"-"},
{id:"scannet",name:"scannet",description:"ScanNet is an instance-level indoor RGB-D dataset that includes both 2D and 3D data. It is a collection of labeled voxels rather than points or objects. Up to now, ScanNet v2, the newest version of ScanNet, has collected 1513 annotated scans with an appr...",link:"http://www.scan-net.org/",category:"Image",field:"Semantic Segmentation",task:"Semantic_Segmentation,Depth_Estimation,3D_Reconstruction",instances:"-",num:"29",tutorial:"-"},
{id:"nyu_depth_v1_v2",name:"nyu depth V1, V2",description:"-",link:"https://cs.nyu.edu",category:"Image",field:"Semantic Segmentation",task:"-",instances:"-",num:"30",tutorial:"-"},
{id:"lip",name:"lip",description:"The LIP (Look into Person) dataset is a large-scale dataset focusing on semantic understanding of a person. It contains 50,00 images with elaborated pixel-wise annotations of 19 semantic human part labels and 2D human poses with 16 key points. The images...",link:"http://sysu-hcp.net/lip/index.php",category:"Image",field:"Semantic Segmentation",task:"Semantic_Segmentation",instances:"-",num:"31",tutorial:"-"},
{id:"ade",name:"ADE",description:"The ADE20K semantic segmentation dataset contains more than 20K scene-centric images exhaustively annotated with pixel-level objects and object parts labels. There are totally 150 semantic categories, which include stuffs like sky, road, grass, and discr...",link:"https://groups.csail.mit.edu/vision/datasets/ADE20K/index.html",category:"Image",field:"Semantic Segmentation",task:"Semantic_Segmentation,Image-to-Image_Translation,Scene_Understanding",instances:"-",num:"32",tutorial:"-"},
{id:"ffhq",name:"ffhq",description:"Flickr-Faces-HQ (FFHQ) consists of 70,000 high-quality PNG images at 1024×1024 resolution and contains considerable variation in terms of age, ethnicity and image background. It also has good coverage of accessories such as eyeglasses, sunglasses, hats,...",link:"https://github.com/NVlabs/ffhq-dataset",category:"Image",field:"Super Resolution",task:"Image_Generation,Image_Super-Resolution,Image_Inpainting",instances:"-",num:"33",tutorial:"-"},
{id:"ucf",name:"ucf",description:"UCF101 dataset is an extension of UCF50 and consists of 13,320 video clips, which are classified into 101 categories. These 101 categories can be classified into 5 types (Body motion, Human-human interactions, Human-object interactions, Playing musical i...",link:"https://www.crcv.ucf.edu/data/UCF101.php#Results_on_UCF101",category:"Video",field:"Action Recognition",task:"Temporal_Action_Localization,Action_Recognition,Action_Detection",instances:"-",num:"34",tutorial:"-"},
{id:"activitynet",name:"Activitynet",description:"The ActivityNet dataset contains 200 different types of activities and a total of 849 hours of videos collected from YouTube. ActivityNet is the largest benchmark for temporal activity detection to date in terms of both the number of activity categories ...",link:"http://mmlab.ie.cuhk.edu.hk/projects/CelebA.html",category:"Video",field:"Action Recognition",task:"Temporal_Action_Localization,Action_Recognition,Action_Classification",instances:"-",num:"35",tutorial:"-"},
{id:"ntu",name:"ntu",description:"-",link:"http://rose1.ntu.edu.sg/datasets/actionrecognition.asp",category:"Video",field:"Action Recognition",task:"-",instances:"-",num:"36",tutorial:"-"},
{id:"kinetics",name:"kinetics",description:"The Kinetics dataset is a large-scale, high-quality dataset for human action recognition in videos. The dataset consists of around 500,000 video clips covering 600 human action classes with at least 600 video clips for each action class. Each video clip ...",link:"https://arxiv.org/abs/1705.06950",category:"Video",field:"Action Recognition",task:"Temporal_Action_Localization,Video_Classification,Action_Recognition",instances:"-",num:"37",tutorial:"-"},
{id:"youtube_8m_segments_dataset",name:"YouTube-8M Segments Dataset",description:"The YouTube-8M dataset is a large scale video dataset, which includes more than 7 million videos with 4716 classes labeled by the annotation system. The dataset consists of three parts: training set, validate set, and test set. In the training set, each ...",link:"http://research.google.com/youtube8m/index.html",category:"Video",field:"Classification",task:"Video_Classification,Video_Prediction",instances:"8 million",num:"38",tutorial:"-"},
{id:"davis_16",name:"davis 16",description:"DAVIS16 is a dataset for video object segmentation which consists of 50 videos in total (30 videos for training and 20 for testing). Per-frame pixel-wise annotations are offered.",link:"https://davischallenge.org/index.html",category:"Video",field:"Object Segmentation",task:"Video_Object_Segmentation,Video_Salient_Object_Detection,Unsupervised_Video_Object_Segmentation",instances:"-",num:"39",tutorial:"-"},
{id:"davis_17",name:"davis 17",description:"DAVIS17 is a dataset for video object segmentation. It contains a total of 150 videos - 60 for training, 30 for validation, 60 for testing",link:"https://davischallenge.org/index.html",category:"Video",field:"Object Segmentation",task:"Semantic_Segmentation,Video_Object_Segmentation,Referring_Expression_Segmentation",instances:"-",num:"40",tutorial:"-"},
{id:"davis_18",name:"davis 18",description:"-",link:"https://davischallenge.org/index.html",category:"Video",field:"Object Segmentation",task:"-",instances:"-",num:"41",tutorial:"-"},
{id:"davis_19",name:"davis 19",description:"-",link:"https://davischallenge.org/index.html",category:"Video",field:"Object Segmentation",task:"-",instances:"-",num:"42",tutorial:"-"},
{id:"mot",name:"MOT",description:"-",link:"https://motchallenge.net/",category:"Video",field:"Object Tracking",task:"-",instances:"-",num:"43",tutorial:"-"},
{id:"vot",name:"vot",description:"-",link:"https://www.votchallenge.net/index.html",category:"Video",field:"Object Tracking",task:"-",instances:"-",num:"44",tutorial:"-"},
{id:"dexter",name:"dexter",description:"-",link:"http://archive.ics.uci.edu/ml//datasets/Dexter",category:"Text",field:"Classification",task:"-",instances:"2600",num:"45",tutorial:"-"},
{id:"ubuntu_dialogue",name:"ubuntu dialogue",description:"Ubuntu Dialogue Corpus (UDC) is a dataset containing almost 1 million multi-turn dialogues, with a total of over 7 million utterances and 100 million words. This provides a unique resource for research into building dialogue managers based on neural lang...",link:"https://ubuntudialogue.org/",category:"Text",field:"Dialogue Generation",task:"Dialogue_Generation,Conversational_Response_Selection,Answer_Selection",instances:"-",num:"46",tutorial:"-"},
{id:"wmt19",name:"wmt19",description:"-",link:"http://www.statmt.org/wmt19/",category:"Text",field:"Machine Translation",task:"-",instances:"-",num:"47",tutorial:"-"},
{id:"wmt18",name:"wmt18",description:"WMT 2018 is a collection of datasets used in shared tasks of the Third Conference on Machine Translation. The conference builds on a series of twelve previous annual workshops and conferences on Statistical Machine Translation. The conference featured...",link:"http://www.statmt.org/wmt18/papers.html",category:"Text",field:"Machine Translation",task:"Machine_Translation",instances:"-",num:"48",tutorial:"-"},
{id:"wmt17",name:"wmt17",description:"-",link:"http://www.statmt.org/wmt17/results.html",category:"Text",field:"Machine Translation",task:"-",instances:"-",num:"49",tutorial:"-"},
{id:"wmt16",name:"wmt16",description:"WMT 2016 is a collection of datasets used in shared tasks of the First Conference on Machine Translation. The conference builds on ten previous Workshops on statistical Machine Translation. The conference featured ten shared tasks: a news translati...",link:"http://www.statmt.org/wmt16/",category:"Text",field:"Machine Translation",task:"Machine_Translation,Unsupervised_Machine_Translation",instances:"-",num:"50",tutorial:"-"},
{id:"wmt15",name:"wmt15",description:"WMT 2015 is a collection of datasets used in shared tasks of the Tenth Workshop on Statistical Machine Translation. The workshop featured five tasks: a news translation task,  a metrics task,  a tuning task,  a quality estimation task,  an automatic p...",link:"http://www.statmt.org/wmt15/",category:"Text",field:"Machine Translation",task:"Machine_Translation",instances:"-",num:"51",tutorial:"-"},
{id:"wmt14",name:"wmt14",description:"WMT 2014 is a collection of datasets used in shared tasks of the Ninth Workshop on Statistical Machine Translation. The workshop featured four tasks: a news translation task,  a quality estimation task,  a metrics task,  a medical text translation task.",link:"http://www.statmt.org/wmt14/",category:"Text",field:"Machine Translation",task:"Machine_Translation,Unsupervised_Machine_Translation",instances:"-",num:"52",tutorial:"-"},
{id:"semeval-2016",name:"SemEval-2016",description:"-",link:"https://alt.qcri.org/semeval2016/index.php?id=tasks",category:"Text",field:"Word Sentiment",task:"-",instances:"-",num:"53",tutorial:"-"},
{id:"bfm",name:"BFM",description:"-",link:"https://faces.dmi.unibas.ch/bfm/?nav=1-0&id=basel_face_model",category:"3-D Image",field:"3-D Estimation",task:"-",instances:"-",num:"53",tutorial:"-"},
{id:"pix3d",name:"Pix3D",description:"The Pix3D dataset is a large-scale benchmark of diverse image-shape pairs with pixel-level 2D-3D alignment. Pix3D has wide applications in shape-related tasks including reconstruction, retrieval, viewpoint estimation, etc.",link:"http://pix3d.csail.mit.edu/",category:"3-D Image",field:"Classification",task:"3D_Shape_Reconstruction,3D_Shape_Modeling,3D_Shape_Classification",instances:"-",num:"55",tutorial:"-"},
{id:"shrec",name:"shrec",description:"The SHREC dataset contains 14 dynamic gestures performed by 28 participants (all participants are right handed) and captured by the Intel RealSense short range depth camera. Each gesture is performed between 1 and 10 times by each participant in two way:...",link:"http://tosca.cs.technion.ac.il/book/shrec_robustness2010.html",category:"3-D Image",field:"Object Recognition",task:"Gesture_Recognition,Hand_Gesture_Recognition,Skeleton_Based_Action_Recognition",instances:"-",num:"56",tutorial:"-"},
{id:"shapenetcore",name:"shapenetCore",description:"-",link:"https://www.shapenet.org/",category:"3-D Image",field:"Semantic Segmentation",task:"-",instances:"-",num:"57",tutorial:"-"},
{id:"faust",name:"faust",description:"The FAUST dataset is a dataset of real 3D scans of humans. It contains 10 scanned human shapes in 10 different poses, resulting in a total of 100 non-watertight meshes with 6,890 nodes each.",link:"http://faust.is.tue.mpg.de/",category:"3-D Image",field:"Semantic Segmentation",task:"Semantic_Segmentation,3D_Reconstruction,3D_Point_Cloud_Matching",instances:"-",num:"58",tutorial:"-"},
{id:"scape",name:"Scape",description:"-",link:"https://ai.stanford.edu/~drago/Projects/scape/scape.html",category:"3-D Image",field:"3-D Estimation",task:"-",instances:"-",num:"59",tutorial:"-"},
{id:"voxceleb",name:"VoxCeleb",description:"-",link:"http://www.robots.ox.ac.uk/~vgg/data/voxceleb/",category:"Sound",field:"Video Reconstruction",task:"-",instances:"-",num:"60",tutorial:"-"}];

var Board=[{title:"안녕하세요",content:"Datawiki에 오신 것을 환영합니다.",date:"2022.05.01",views:"10"},
{title:"관리자소개",content:"Datawiki의 관리자를 소개 합니다.",date:"2022.05.05",views:"5"},
{title:"최신 뉴스",content:"Datawiki는 상명대 천안캠퍼스에서 주관하는 데이터 공유 사이트 입니다.",date:"2022.05.06",views:"22"},
{title:"공지사항",content:"Datawiki가 새롭게 단장됩니다. 더욱 개선된 사이트를 기대해 주세요.",date:"2022.05.08",views:"100"},
{title:"추가 공지 사항",content:"Datawiki를 새롭게 개선하기 위한 메니저를 공모합니다. ",date:"2022.05.10",views:"1"},
{title:"2022년 데이터위키 공모전",content:"2022년 데이터 위키는 이미지 인식 주제로 진행합니다.",date:"2022.05.12",views:"44"},
{title:"공모전 종료 안내",content:"2022년 데이터 위키 공모전이 성공리에 마감 되었습니다. ",date:"2022.05.14",views:"50"},
{title:"2023년 데이터 위키 공모전",content:"2023년 데이터 위키 공모전을 소개 합니다.",date:"2022.05.16",views:"49"},
{title:"학기 종료 안내",content:"22년 1학기 종료까지 이제 6주 남았습니다. ",date:"2022.05.18",views:"17"},
{title:"튜토리얼 공지",content:"tensorflow와 keras의 라이브러리를 이용하여 같이 공부해 봅시다.",date:"2022.05.19",views:"84"},
{title:"신규 데이터 요청",content:"새로운 데이터가 필요하신 분은 언제든 요청 바랍니다.",date:"2022.05.21",views:"3"}];

var Colosseum=[{title:"천하제일 얼굴 인식대회",startdate:"2022.04.01",enddate:"2022.05.01",id:"celebA"},
{title:"도로위 인식의 최강자 선발 대회",startdate:"2022.06.01",enddate:"2022.07.01",id:"kitti"},
{title:"Did you understand what I said?",startdate:"2022.08.01",enddate:"2022.09.01",id:"wmt19"}];

//DataWiki의 데이터 정렬 기준을 선택하는 함수
function sortfunction(){

    var x=document.getElementById('myselect').value;

    if(x=="Name"){
        const element = document.getElementById('content');
        element.innerText = '';

        DataInfo.sort(function(a, b) { 
    return a.name < b.name ? -1 : a.name > b.name ? 1 : 0;
        });
    for(i=0;i<DataInfo.length;i++){
        var a='<a id="asdf" name="asdf" href="javascript:void();" onclick="printpage('+i+')" target="DataWikiIframe">'
        +DataInfo[i].name+'</a><br>';
    var b= document.getElementById('content');
    b.innerHTML=b.innerHTML+a;}
    }

    else if(x=="Category"){
        const element = document.getElementById('content');
        element.innerText = '';

        DataInfo.sort(function(a, b) { 
            return a.name < b.name ? -1 : a.name > b.name ? 1 : 0;
                });
        DataInfo.sort(function(a, b) { 
            return a.category < b.category ? -1 : a.category > b.category ? 1 : 0;
                });

        for(i=0;i<DataInfo.length;i++){
            if(DataInfo[i].category!='-'){
                var a='<a id="asdf" name="asdf" href="javascript:void();" onclick="printpage('+i+')" target="DataWikiIframe">'
    +DataInfo[i].name+'</a><br>';
                var b= document.getElementById('content');
                b.innerHTML=b.innerHTML+a;
        }
}
    }

    else if(x=="Task"){
        const element = document.getElementById('content');
        element.innerText = '';

        var sortingField="task";
    DataInfo.sort(function(a, b) {
        return a.task < b.task ? -1 : a.task > b.task ? 1 : 0;
    });
    for(i=0;i<DataInfo.length;i++){
        if(DataInfo[i].task!="-"){
            var a='<a id="asdf" name="asdf" href="javascript:void();" onclick="printpage('+i+')" target="DataWikiIframe">'
            +DataInfo[i].name+'</a><br>';
    var b= document.getElementById('content');
    b.innerHTML=b.innerHTML+a;
    }
    }
    }

    else if(x=="Tutorial"){
        const element = document.getElementById('content');
        element.innerText = '';

        var sortingField="tutorial";
    DataInfo.sort(function(a, b) { 
        return a.tutorial < b.tutorial ? -1 : a.tutorial > b.tutorial ? 1 : 0;
    });
    for(i=0;i<DataInfo.length;i++){
        if(DataInfo[i].tutorial!="-"){
            var a='<a id="asdf" name="asdf" href="javascript:void();" onclick="printpage('+i+')" target="DataWikiIframe">'
            +DataInfo[i].name+'</a><br>';
    var b= document.getElementById('content');
    b.innerHTML=b.innerHTML+a;
    }
    }
    }

};

function printpagefirst(){
    var myIFrameObj = document.getElementById('DataWikiIframe');
    myIFrameObj = (myIFrameObj.contentWindow)  ? myIFrameObj.contentWindow  : (myIFrameObj.contentDocument.document)    ? myIFrameObj.contentDocument.document    : myIFrameObj.contentDocument;myIFrameObj.document.open();
    myIFrameObj.document.write("<h1>이름 : "+DataInfo[0].name+"</h1>");
    myIFrameObj.document.write("<ul>");
    myIFrameObj.document.write("<li>- 데이터 분류 : "+DataInfo[0].category+"</li>");
    myIFrameObj.document.write("<li>- 데이터 수 : "+DataInfo[0].instances+"</li>");
    myIFrameObj.document.write("<li>- 데이터 목적 : "+DataInfo[0].task+"</li>");
    myIFrameObj.document.write("<li>- 데이터 설명 : "+DataInfo[0].description+"</li>");
    myIFrameObj.document.write("</ul>");
    myIFrameObj.document.write('<a class="infolink" href="'+DataInfo[0].link+ '" target="infoiframe" >'+"데이터 링크"+'</a>');
    myIFrameObj.document.write('<a class="infolink" href="'+DataInfo[0].tutorial+'" target="infoiframe">'+" &nbsp&nbsp&nbsp&nbsp튜토리얼 링크"+'</a><br>');
    myIFrameObj.document.write('<iframe class="infoiframe" name="infoiframe" width="790px" height="700px ></iframe>');
    myIFrameObj.document.close();
    }

    function printpage(x){
        var myIFrameObj = document.getElementById('DataWikiIframe');
        myIFrameObj = (myIFrameObj.contentWindow)  ? myIFrameObj.contentWindow  : (myIFrameObj.contentDocument.document)    ? myIFrameObj.contentDocument.document    : myIFrameObj.contentDocument;myIFrameObj.document.open();
        myIFrameObj.document.write("<h1>이름 : "+DataInfo[x].name+"</h1>");
        myIFrameObj.document.write("<ul>");
        myIFrameObj.document.write("<li>- 데이터 분류 : "+DataInfo[x].category+"</li>");
        myIFrameObj.document.write("<li>- 데이터 수 : "+DataInfo[x].instances+"</li>");
        myIFrameObj.document.write("<li>- 데이터 목적 : "+DataInfo[x].task+"</li>");
        myIFrameObj.document.write("<li>- 데이터 설명 : "+DataInfo[x].description+"</li>");
        myIFrameObj.document.write("</ul>");
        if(DataInfo[x].link!=="-"){
        myIFrameObj.document.write('<a class="infolink" href="'+DataInfo[x].link+ '" target="infoiframe" >'+"데이터 링크"+'</a>');
        }
        if(DataInfo[x].tutorial!=="-"){
        myIFrameObj.document.write('<a class="infolink" href="'+DataInfo[x].tutorial+'" target="infoiframe">'+" &nbsp&nbsp&nbsp&nbsp튜토리얼 링크"+'</a><br>');
        }
        myIFrameObj.document.write('<iframe id="infoiframe" class="infoiframe" name="infoiframe" width="729px" height="700px"></iframe>');
        myIFrameObj.document.close();
        }

        