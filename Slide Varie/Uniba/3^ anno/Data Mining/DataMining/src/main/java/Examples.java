import java.io.FileReader;
import java.util.Arrays;
import java.util.Random;

import weka.core.Instance;
import weka.core.Instances;
import weka.core.Attribute;

import weka.filters.Filter;
import weka.filters.unsupervised.attribute.Remove;

import weka.classifiers.Classifier;
import weka.classifiers.Evaluation;
import weka.classifiers.bayes.NaiveBayes;
import weka.classifiers.functions.LinearRegression;
import weka.classifiers.functions.Logistic;
import weka.classifiers.functions.MultilayerPerceptron;
import weka.classifiers.functions.SMO;
import weka.classifiers.lazy.IBk;
import weka.classifiers.rules.PART;
import weka.classifiers.trees.J48;
import weka.classifiers.trees.M5P;
import weka.classifiers.trees.RandomForest;

import weka.clusterers.SimpleKMeans;

public class Examples {

	private static final String ROOT_PATH = "";

	private static final String DATASET_PATH = ROOT_PATH + "filteredData.arff";
	
	private static final int[] CLASS_INDEXES = {0,1};
	
	private static final int K_FOLDS = 10;

	private static final Classifier[] CLASSIFIERS = 
		{
			new IBk(),
			new J48(),
			new MultilayerPerceptron(),
			new NaiveBayes(),
			new PART(),
			new Logistic(),
			new RandomForest(),
			new SMO()
		};
	
	private static final Classifier[] REGRESSORS = 
		{
				new IBk(),
				new M5P(),
				new LinearRegression(),
				new MultilayerPerceptron(),
				new RandomForest()
		};

	// num clusters
	private static final int NUM_CLUSTERS = 3;

	public static void main(String[] args) throws Exception {

		long start = System.currentTimeMillis();

		// Carica il dataset
		Instances dataset = new Instances(new FileReader(DATASET_PATH));

		// Stampa il numero di attributi dopo la rimozione
		System.out.println(dataset.numAttributes());

		// Rimozione variabile target
		String[] options = new String[2];
		options[0] = "-R";													// "range"
		options[1] = "1";													// first attribute (indici partono da 1 UNO)
		Remove remove = new Remove();										// new instance of filter
		remove.setOptions(options);											// set options
		remove.setInputFormat(dataset);										// inform filter about dataset **AFTER** setting options
		Instances unsupervisedDataset = Filter.useFilter(dataset, remove);	// apply filter

		// Stampa il numero di attributi dopo la rimozione
		System.out.println(unsupervisedDataset.numAttributes());

		for(int CLASS_INDEX : CLASS_INDEXES)
		{
			// Vogliamo effettuare il task di classificazione. Pertanto è necessario indicare l'indice di classe del dataset
			dataset.setClassIndex(CLASS_INDEX);

			// Stampa il numero di istanze
			System.out.println(dataset.numInstances());

			// Stampa il numero di attributi
			System.out.println(dataset.numAttributes());

			// Itera sulle istanze del dataset
			for(int i = 0; i < dataset.numInstances(); i++)
			{
				// Indici partono da 0 ZERO
				Instance instance = dataset.instance(i);
				// fai qualcosa
			}

			// Itera sulle istanze del dataset (for generalizzato)
			for(Instance instance : dataset)
			{
				// fai qualcosa
			}

			// Itera sugli attributi del dataset
			for(int i = 0; i < dataset.numAttributes(); i++)
			{
				// Indici partono da 0 ZERO
				Attribute attribute = dataset.attribute(i);
				// fai qualcosa
			}

			String name = dataset.attribute(CLASS_INDEX).name();
			System.out.println("Class name: " + name);
			String string = dataset.attribute(CLASS_INDEX).toString();
			System.out.println("Class string: " + string);

			// la variabile target
			Attribute targetVariable = dataset.attribute(CLASS_INDEX);

			// in weka l'interfaccia Classifier è usata sia per classificatori che per regressori
			Classifier[] methods;

			// controllo se la variabile target è categorica o numerica
			boolean isNominal = targetVariable.isNominal();
			if(isNominal) methods = CLASSIFIERS;
			else methods = REGRESSORS;

			for(Classifier method : methods)
			{
				String classifierName = method.getClass().toString().split("\\.")[method.getClass().toString().split("\\.").length - 1];
				System.out.println(classifierName);
				// 10-fold cross-validation
				Evaluation ev = new Evaluation(dataset);
				ev.crossValidateModel(method, dataset, K_FOLDS, new Random(123));

				// stampa il summary (valido sia per classificazione che per regressione)
				String summary = ev.toSummaryString();
				System.out.println("SUMMARY");
				System.out.println(summary);

				// se la variablie target è nominale allora il task è di classificazione. Quindi consideriamo alcune misure di valutazione per il task di classificazione
				if(isNominal)
				{
					System.out.println("CONFUSION MATRIX");
					printMatrix(ev.confusionMatrix());
					System.out.println("STATISTICS");
					String statistics = ev.toClassDetailsString();
					System.out.println(statistics);
					double accuracy = ev.pctCorrect();
					System.out.println("ACCURACY");
					System.out.println(accuracy);
					System.out.println("AREA UNDER PRECISION RECALL CURVE");
					double AUPRC = ev.areaUnderPRC(CLASS_INDEX);
					System.out.println(AUPRC);
					System.out.println("AREA UNDER ROC CURVE");
					double AUROC = ev.areaUnderROC(CLASS_INDEX);
					System.out.println(AUROC);
				}
				// altrimenti il task è di regressione. Quindi consideriamo alcune misure di valutazione per il task di classificazione
				else
				{
					System.out.println("ROOT MEAN SQUARED ERROR");
					double RMSE = ev.rootMeanSquaredError();
					System.out.println(RMSE);
					System.out.println("MEAN ABSOLUTE ERROR");
					double MAE = ev.meanAbsoluteError();
					System.out.println(MAE);
				}
			}
		}

		SimpleKMeans kmeans = new SimpleKMeans();
		kmeans.setNumClusters(NUM_CLUSTERS);
		kmeans.buildClusterer(unsupervisedDataset);

		// prendere le istanze centroide
		Instances centroids = kmeans.getClusterCentroids();
		for(Instance centroid : centroids)
		{
			System.out.println(centroid.toString());
		}

		// alcuni output possibili
		for(Instance instance : unsupervisedDataset)
		{
			System.out.println("ASSEGNAMENTO AL CLUSTER PIù VICINO PER ISTANZA CORRENTE");
			System.out.println(kmeans.clusterInstance(instance));
			System.out.println("DISTRIBUZIONE DELL'ASSEGNAMENTO AI CLUSTER PER ISTANZA CORRENTE");
			System.out.println(Arrays.toString(kmeans.distributionForInstance(instance)));
		}

		// stampo i tempi di esecuzione
		long end = System.currentTimeMillis();
		double executionTime = ((double)(end - start) / 1000d);
		System.out.println("Execution time : " + executionTime + " seconds");
		System.out.println();
	}
		
	private static void printMatrix(double[][] matrix)
	{
		for (double[] doubles : matrix) {
			for (double aDouble : doubles) {
				System.out.print(aDouble + " ");
			}
			System.out.println();
		}
	}

}
