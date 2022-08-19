import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;

public class DataCleaning {

    private static final String IMPOSSIBLE_DATASET_PATH = "C:/Users/pauln/Desktop/AnimeList.csv";

    private static final String SEPARATOR = ",";

    private static final boolean HAS_HEADER = true;

    private static final String TEXT_CONTENT_CHARACTER_ENCLOSER = "\"";

    private static int featureSet;

    public static void main(String[] args) throws IOException {

        BufferedReader readerImpossibleDataset = new BufferedReader(new FileReader(new File(IMPOSSIBLE_DATASET_PATH)));
        String header;

        if(HAS_HEADER) header = readerImpossibleDataset.readLine();

        String[] splitHeader = header.split(SEPARATOR);

        featureSet = splitHeader.length;

        String line;
        while((line = readerImpossibleDataset.readLine()) != null)
        {
            String[] splitLine = line.split(SEPARATOR);
            int size = splitLine.length;
            if(size < featureSet)
            {
                System.out.println("MENO VIRGOLE!");
                System.out.println(line);
            }
            if(size > featureSet)
            {
                System.out.println("PIù VIRGOLE!");
                System.out.println(line);
            }

        }
    }

    public String getCleanLineContent(String rawLine)
    {


    }

}
